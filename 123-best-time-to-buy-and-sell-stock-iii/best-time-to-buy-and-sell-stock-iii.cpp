class Solution {
public:
    int f(int i, int b, vector<int>& prices ,vector<vector<vector<int>>> &dp,int c){
        int n=prices.size();
        if(c==0) return 0;
        if(i==n) return 0;
        int profit=0;
        if(dp[i][b][c]!=-1) return dp[i][b][c];
        if(b){
            profit=max(-prices[i]+f(i+1,0,prices,dp,c),f(i+1,1,prices,dp,c));
        }
        else{
            profit=max(prices[i]+f(i+1,1,prices,dp,c-1),f(i+1,0,prices,dp,c));
        }

        return dp[i][b][c]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,prices,dp,2);
    }
};