class Solution {
public:
/*
    int f(int i, int b, vector<int>& prices ,vector<vector<int>> &dp,int &fee){
        int n=prices.size();
        if(i==n) return 0;
        int profit=0;
        if(dp[i][b]!=-1) return dp[i][b];
        if(b){
            profit=max(-prices[i]+f(i+1,0,prices,dp,fee),f(i+1,1,prices,dp,fee));
        }
        else{
            profit=max(prices[i]+f(i+1,1,prices,dp,fee)-fee,f(i+1,0,prices,dp,fee));
        }

        return dp[i][b]=profit;
    }
    */
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        //vector<vector<int>> dp(n,vector<int>(2,-1));
        //return f(0,1,prices,dp,fee);
        
        vector<vector<int>> dp(n+1,vector<int>(2,0));

       
        for(int i=n-1;i>=0;i--){
            for(int b=0;b<2;b++){
                int profit=0;
                if(b){
                    profit=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else{
                    profit=max(prices[i]+dp[i+1][1]-fee,dp[i+1][0]);
                }
                dp[i][b]=profit;
            }
        }

        return (int)dp[0][1];
        
    }
};