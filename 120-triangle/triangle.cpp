class Solution {
public:
/* memoization , GAVE TLE
    int tri(int i,int j,vector<vector<int>> &triangle,int n,vector<vector<int>> &dp){
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(i==n-1) return triangle[i][j];
        int down=triangle[i][j]+tri(i+1,j,triangle,n,dp);
        int diag=triangle[i][j]+tri(i+1,j+1,triangle,n,dp);

        return dp[i][j]=min(down,diag);
    }
    */

    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,0));

        for(int j=0;j<n;j++){
            dp[n-1][j]=triangle[n-1][j];
        }
        // Traverse from second-last row to the top
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                // Calculate sum from down and diagonal paths
                int down = triangle[i][j] + dp[i + 1][j];
                int diag = triangle[i][j] + dp[i + 1][j + 1];

                // Store the minimum of the two paths
                dp[i][j] = min(down, diag);
            }
        }

        // Return the minimum path sum from top
        return dp[0][0];


        /*
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        if(n==1) return triangle[0][0];
        return tri(0,0,triangle,n,dp);
        */
    }
};