class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> anaofs;
        vector<int> anaoft;
        if(s.length()!=t.length()) return false;
        if(s==t) return true;
        for(int i=0; i<s.length();i++){
            anaofs.push_back(s[i]);
            anaoft.push_back(t[i]);
        }

        std::sort(anaofs.begin(),anaofs.end());
        std::sort(anaoft.begin(),anaoft.end());
        for(int j=0; j<s.length();j++){
            if(anaofs[j]!=anaoft[j]) return false;
        }

        return true;
    }
};