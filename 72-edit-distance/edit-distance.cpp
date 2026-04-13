class Solution {
public:
/// https://www.youtube.com/watch?v=fJaKO8FbDdo&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=35
    /*int f(int i , int j,string &s, string &t,vector<vector<int>> &dp){      
        if(i<0) return j+1;
        if(j<0) return i+1;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==t[j]) return dp[i][j]=f(i-1,j-1,s,t,dp);
        return dp[i][j]=1+min(f(i,j-1,s,t,dp),min(f(i-1,j,s,t,dp),f(i-1,j-1,s,t,dp)));
    }
    */
    int minDistance(string word1, string word2) {
        int k=word1.size();
        int l=word2.size();
        vector<vector<int>> dp(k+1,vector<int>(l+1,0));
        /*int r=f(k-1,l-1,word1,word2,dp);
        return r;*/

        for(int i=0;i<=k;i++) dp[i][0]=i;
        for(int j=0;j<=l;j++) dp[0][j]=j;


        for(int i=1;i<=k;i++){
            for(int j=1;j<=l;j++){
                if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
            }
        }

        return dp[k][l];
    }
};