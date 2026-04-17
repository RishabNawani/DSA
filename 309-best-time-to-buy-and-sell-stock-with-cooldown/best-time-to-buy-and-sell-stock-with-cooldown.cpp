class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        vector<vector<int>> dp(n+2,vector<int>(2,0));
        dp[n][0]=dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int b=0;b<2;b++){
                int profit=0;
                if(b){
                    profit=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else{
                    profit=max(prices[i]+dp[i+2][1],dp[i+1][0]);
                }
                dp[i][b]=profit;
            }
        }

        return (int)dp[0][1];
    }
};