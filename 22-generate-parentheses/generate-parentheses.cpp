class Solution {
public:
    void generatee(int n, int open, int close, std::string str, vector<string>& ress){
        if(str.length() == 2*n){
            ress.push_back(str);
            return;
        }

        if(open<n){
            generatee(n,open+1,close,str+"(",ress);
        }
        if(close<open){
            generatee(n,open,close+1,str+")",ress);
        }
    }

    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generatee(n,0,0,"",res);
        return res;
    }
};