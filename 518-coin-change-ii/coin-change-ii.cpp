// both int and long/long long caused overflow , so used unsigned int and convert to int in the end.
class Solution {
public:

    int ans(int ind , int t, vector<int>& coins , vector<vector<int>>& dp){
        if(ind==0) return (int)(t%coins[0]==0);
        if(dp[ind][t]!=-1) return dp[ind][t];
        int nottake=ans(ind-1,t,coins,dp);
        int take=0;
        if(coins[ind]<=t) take=ans(ind,t-coins[ind],coins,dp);
        return dp[ind][t]=take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        // tabulation
        /*
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
        */
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return (int)ans(n-1,amount,coins,dp);
    }
};