class Solution {
public:
    bool static comp(string &s , string &t){
        return s.size()<t.size();
    }

    bool checkk(string &s, string &t){
        if(s.size()!=t.size()+1) return false;
        int i=0;
        int j=0;
        while(i<s.size()){
            if(j<t.size() && s[i]==t[j]){
                i++; j++;
            }
            else{
                i++;
            }
        }
        if(i==s.size() && j==t.size()) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),comp);
        vector<int> dp(n,1);
        int maxx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(checkk(words[i],words[j]) && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
            }
            if(dp[i]>maxx) maxx=dp[i];
        }
        return maxx;
    }
};