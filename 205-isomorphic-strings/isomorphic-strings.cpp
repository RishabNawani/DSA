class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;

        vector<int> mapss(256,0);
        vector<int> mapst(256,0);

        for(int i=0;i<s.length();i++){
            char c1=s[i];
            char c2=t[i];

            if(mapss[c1]==0 && mapst[c2]==0){
                mapss[c1]=c2;
                mapst[c2]=c1;
            }
            else{
                if(mapss[c1]!=c2 || mapst[c2]!=c1) return false;
            }
        }
        return true;
/*
        int n=s.length();
        if(s.length()!=t.length()) return false;
        for(int i=0; i<n; i++){
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j]){
                    if(t[i]!=t[j]) return false;
                }
                if(t[i]==t[j]){
                    if(s[i]!=s[j]) return false;
                }
            }
        }
        return true;
*/     
    }
};