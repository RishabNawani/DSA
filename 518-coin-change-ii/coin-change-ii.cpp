class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<unsigned int>> dp(n,vector<unsigned int>(amount+1,-1));
        for(int t=0;t<=amount;t++){
            if(t%coins[0]==0) dp[0][t]=1;
            else dp[0][t]=0;
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                unsigned int nottake=dp[i-1][j];
                unsigned int take=0;
                if(coins[i]<=j) take=dp[i][j-coins[i]];
                dp[i][j]=(nottake+take);
            }
        }

        return (int)dp[n-1][amount];
    }
};