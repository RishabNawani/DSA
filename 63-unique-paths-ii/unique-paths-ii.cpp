class Solution {
public:
    int sol(int i,int j,vector<vector<int>> &dp, vector<vector<int>> &obs){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(obs[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=sol(i-1,j,dp,obs);
        int left=sol(i,j-1,dp,obs);
        return dp[i][j]=up+left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1) return 0;
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return sol(m-1,n-1,dp,obstacleGrid);
    }
};