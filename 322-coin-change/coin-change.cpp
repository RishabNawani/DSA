/*
can be solved using take and non take , whenever you choose non take , set not take = 0+f(ind-1,target), move the index left , whenevr you choose take , choose it only when coins[ind]<=target and take=1+f(ind, target-coin[ind]), we stay at the same place because there are an infinite number of coins present.

so , we store the targets previously , because due to recursion , tc and sc were coming hugeeeeeee, which gave error

tabulation is the wayyy.
*/


class Solution {
public:
/* recursion solution
    int ans(int i,vector<int> &coins, int tar){
        if(i==0){
            if(tar%coins[i]==0) return tar/coins[i];
            else return 1e9;
        }

        int nottake=0+ans(i-1,coins,tar);
        int take=INT_MAX;
        if(coins[i]<=tar) take=1+ans(i,coins,tar-coins[i]);

        return min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int a=ans(n-1,coins,amount);
        if(a>=1e9) return -1;
        return a;
        */

        /* memoization solution
    int ans(int i,vector<int> &coins, int tar,vector<vector<int>> &dp){
        if(i==0){
            if(tar%coins[i]==0) return tar/coins[i];
            else return 1e9;
        }
        if( dp[i][tar]!=-1) return dp[i][tar];
        int nottake=0+ans(i-1,coins,tar,dp);
        int take=INT_MAX;
        if(coins[i]<=tar) take=1+ans(i,coins,tar-coins[i],dp);

        return dp[i][tar]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int a=ans(n-1,coins,amount,dp);
        if(a>=1e9) return -1;
        return a;
        */
        int coinChange(vector<int>& coins, int amount) {
            int n=coins.size();
            vector<vector<int>> dp(n,vector<int>(amount+1,-1));
            for(int t=0;t<=amount;t++){
                if(t % coins[0]==0)dp[0][t]=t/coins[0];
                else dp[0][t]=1e9;
            }

            for(int i=1;i<n;i++){
                for(int t=0;t<=amount;t++){
                    int nottake=0+dp[i-1][t];
                    int take=INT_MAX;
                    if(coins[i]<=t) take=1+dp[i][t-coins[i]];
                    dp[i][t]=min(take,nottake);
                }

            }
            
            int a=dp[n-1][amount];
            if(a>=1e9) return -1;
            return a;
    }
};