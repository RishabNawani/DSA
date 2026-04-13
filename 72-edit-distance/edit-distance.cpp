class Solution {
public:
    int f(int i , int j,string &s, string &t,vector<vector<int>> &dp){      
        if(i<0) return j+1;
        if(j<0) return i+1;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==t[j]) return dp[i][j]=f(i-1,j-1,s,t,dp);
        return dp[i][j]=1+min(f(i,j-1,s,t,dp),min(f(i-1,j,s,t,dp),f(i-1,j-1,s,t,dp)));
    }
    int minDistance(string word1, string word2) {
        int k=word1.size();
        int l=word2.size();
        vector<vector<int>> dp(k,vector<int>(l,-1));
        int r=f(k-1,l-1,word1,word2,dp);
        return r;
    }
};