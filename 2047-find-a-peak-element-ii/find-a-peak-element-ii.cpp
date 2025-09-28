
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // ✅ Corner checks
        if (n == 1 && m == 1) return {0, 0};
        if (n == 1) {
            for (int j = 0; j < m; j++) {
                if ((j == 0 || mat[0][j] > mat[0][j-1]) &&
                    (j == m-1 || mat[0][j] > mat[0][j+1]))
                    return {0, j};
            }
        }
        if (m == 1) {
            for (int i = 0; i < n; i++) {
                if ((i == 0 || mat[i][0] > mat[i-1][0]) &&
                    (i == n-1 || mat[i][0] > mat[i+1][0]))
                    return {i, 0};
            }
        }

        // ✅ Border checks
        for (int j = 0; j < m; j++) {
            if ((j == 0 || mat[0][j] > mat[0][j-1]) &&
                (j == m-1 || mat[0][j] > mat[0][j+1]) &&
                mat[0][j] > mat[1][j])
                return {0, j};
        }
        for (int j = 0; j < m; j++) {
            if ((j == 0 || mat[n-1][j] > mat[n-1][j-1]) &&
                (j == m-1 || mat[n-1][j] > mat[n-1][j+1]) &&
                mat[n-1][j] > mat[n-2][j])
                return {n-1, j};
        }
        for (int i = 0; i < n; i++) {
            if ((i == 0 || mat[i][0] > mat[i-1][0]) &&
                (i == n-1 || mat[i][0] > mat[i+1][0]) &&
                mat[i][0] > mat[i][1])
                return {i, 0};
        }
        for (int i = 0; i < n; i++) {
            if ((i == 0 || mat[i][m-1] > mat[i-1][m-1]) &&
                (i == n-1 || mat[i][m-1] > mat[i+1][m-1]) &&
                mat[i][m-1] > mat[i][m-2])
                return {i, m-1};
        }

        // ✅ Interior scan (linear, but works)
        for (int i = 1; i < n-1; i++) {
            for (int j = 1; j < m-1; j++) {
                if (mat[i][j] > mat[i-1][j] && mat[i][j] > mat[i+1][j] &&
                    mat[i][j] > mat[i][j-1] && mat[i][j] > mat[i][j+1])
                    return {i, j};
            }
        }

        return {-1, -1}; // should not happen
    }
};

/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int left = 0, right = m - 1;
        while (left <= right) {
            int midCol = left + (right - left) / 2;

            // find row index of the maximum element in midCol
            int maxRow = 0;
            for (int r = 1; r < n; ++r) {
                if (mat[r][midCol] > mat[maxRow][midCol])
                    maxRow = r;
            }

            int cur = mat[maxRow][midCol];
            int leftVal  = (midCol - 1 >= 0) ? mat[maxRow][midCol - 1] : INT_MIN;
            int rightVal = (midCol + 1 < m) ? mat[maxRow][midCol + 1] : INT_MIN;

            // if current is greater than both horizontal neighbors -> peak
            if (cur > leftVal && cur > rightVal) {
                return {maxRow, midCol};
            }

            // else move to the side which has a larger neighbor
            if (leftVal > cur) {
                // a bigger value is on the left, go left
                right = midCol - 1;
            } else {
                // a bigger value is on the right, go right
                left = midCol + 1;
            }
        }

        return {-1, -1}; // should not happen given problem guarantees
    }
};
*/
