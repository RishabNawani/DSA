class Solution {
public:
    bool wordd(string& s, vector<string>& worddd,int index,vector<int>& dp){
        if(index==s.size()){
            return true;
        }
        if(dp[index]!=-1) return dp[index];

        for(string& word: worddd){
            int len=word.size();
            if(index+len<=s.size() && s.substr(index,len)==word){
                if(wordd(s,worddd,index+len,dp)) return dp[index]=true;
            }
        }

        return dp[index]=false;


    }


    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(),-1);
        int index=0;
        return wordd(s, wordDict,index,dp);
    }
};
/*
    bool wordd(string& s, vector<string>& word,int index){
        if(index==s.size()){
            return true;
        }
        for(int i=0; i<word.size();i++){
            if(word[i]==s) return true;
        }

        for(int l=1;l<=s.size();l++){
            string temp= s.substr(index,l);
            for(int j=0; j<word.size();j++){
                if(word[j]==temp && wordd(s,word,index+l)){
                    return true;
                }
            }
        }

        return false;
    }


    bool wordBreak(string s, vector<string>& wordDict) {
        int index=0;
        return wordd(s, wordDict,index);
    }
};


unordered_set<string> st;
    bool wordd(string& s, vector<string>& word,int index){
        if(index==s.size()){
            return true;
        }
        
        if(st.find(s)!=st.end()) return true;
        

        for(int l=1;l<=s.size();l++){
            string temp= s.substr(index,l);
        
            if(st.find(temp)!=st.end() && wordd(s,word,index+l)){
               return true;
            }
        }

        return false;
    }


    bool wordBreak(string s, vector<string>& wordDict) {
        for(int i=0; i<wordDict.size();i++){
            st.insert(wordDict[i]);
        }
        int index=0;
        return wordd(s, wordDict,index);
    }
};
*/