class Solution {
public:
/*
    bool f(int i, int j, string &s, string &p, vector<vector<int>> &dp){
    
        if(i<0 && j<0) return true;
        if(j>=0 && i<0) return false;
        if(j<0 && i>=0){
            for(int k=0;k<=i;k++){
                if(p[k]!='*') return false;
            }
            return true;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[j]==p[i] || p[i]=='?') return dp[i][j]=f(i-1,j-1,s,p,dp);

        if(p[i]=='*') return dp[i][j]=f(i-1,j,s,p,dp) | f(i,j-1,s,p,dp);

        return false;
        
    }
*/
    bool isMatch(string s, string p) {
        int n=p.size();
        int m=s.size();
        vector<vector<bool>> dp(n+1,vector<bool> (m+1,0));

        dp[0][0]=true;
        for(int j=1;j<=m;j++) dp[0][j]=false;
        for(int i=1;i<=n;i++){
            bool fl=true;
            for(int k=1;k<=i;k++){
                if(p[k-1]!='*'){
                    fl=false;
                    break;
                }
            }
            dp[i][0]=fl;    
        }


        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[j-1]==p[i-1] || p[i-1]=='?') dp[i][j]=dp[i-1][j-1];

                else if(p[i-1]=='*') dp[i][j]=dp[i-1][j] | dp[i][j-1];

                else dp[i][j]=false;
            }
        }

        return dp[n][m];
        /*vector<vector<int>> dp(n,vector<int>(m,-1));

        return f(n-1,m-1,s,p,dp);
        */
    }
};