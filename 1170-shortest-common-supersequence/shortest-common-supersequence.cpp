class Solution {
public:
    string lcs(string &s, string &t){
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int j=0;j<=m;j++) dp[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];// imagine a matrix , each index representing the length of the subsequence before that , now if common , then the subsequences are attached so we add from the diagonal , we solve like they are a substring till this part.
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);// we check the neighbours , except diagonal to see the last longest subsequence , as they can be disconnected . If it was a substring , then would have set it as 0.
            }
        }

        string lcs="";
        int i=n;int j=m;
        while(i>0 && j>0){
            if(s[i-1]==t[j-1]){
                lcs+=s[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]) i--;
            else j--;
        } 

        reverse(lcs.begin(),lcs.end());
        return lcs;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        if(str1==str2) return str1;
        string k=lcs(str1, str2);

        string ans="";
        int i=0; int j=0;
        for(char ch: k){
            while(i<str1.size() && str1[i]!=ch){
                ans+=str1[i];
                i++;
            }
            while(j<str2.size() && str2[j]!=ch){
                ans+=str2[j];
                j++;
            }

            ans+=ch;
            i++;j++;
        }

        ans+=str1.substr(i);
        ans+=str2.substr(j);

        return ans;

    }
};