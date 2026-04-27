class Solution {
public:
    bool ispalin(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int f(string &s,int i,int n,vector<int> &dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int cst=INT_MAX;
        for(int j=i;j<n;j++){
            if(ispalin(i,j,s)){
                int cost=1+f(s,j+1,n,dp);
                cst=min(cst,cost);
            }
        }
        return dp[i]=cst;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return f(s,0,n,dp)-1;
    }
};