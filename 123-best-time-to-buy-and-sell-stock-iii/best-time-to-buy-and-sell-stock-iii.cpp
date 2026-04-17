class Solution {
public:
/*
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
    */
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        //vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        //return f(0,1,prices,dp,2);
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
/// no need to write base cases as all of them already zero , but still wrote it for fun knowledge
        for(int i=0;i<=n;i++){
            for(int b=0;b<2;b++){
                dp[i][b][0]=0;
            }
        }
        for(int b=0;b<2;b++){
            for(int c=0;c<3;c++){
                dp[n][b][c]=0;
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int b=0;b<2;b++){
                for(int c=1;c<3;c++){// c=0 is a base case , so we dont go there
                    if(b){
                        dp[i][b][c]=max(-prices[i]+dp[i+1][0][c],dp[i+1][1][c]);
                    }
                    else{
                        dp[i][b][c]=max(prices[i]+dp[i+1][1][c-1],dp[i+1][0][c]);
                    }
                }
            }
        }
        return dp[0][1][2];       
    }
};