class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int cnt=0;
        int low=0, high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            for(int j=0; j<m;j++){
                if(matrix[mid][j]<target) low =mid+1;
                else if(matrix[mid][j]>target) high=mid-1;
                else return true;
            }

        }
        return false;
        /*
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==target) cnt=1;
            }
        }
        if(cnt==1) return true;
        else return false;
        */
    }
};