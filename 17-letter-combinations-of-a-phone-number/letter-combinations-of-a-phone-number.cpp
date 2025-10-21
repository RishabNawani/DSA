class Solution {
public:
    void digitt(int ind,std::string digits, vector<string>& result,std::string str,vector<string> stor){
        if(ind==digits.length()){
            result.push_back(str);
            return;
        }
        int digit=digits[ind]-'0';
        for(int i=0; i<stor[digit].size();i++){
            digitt(ind+1,digits,result,str+stor[digit][i],stor);
        }
        
    }


    vector<string> letterCombinations(string digits) {
        vector<string> result;
        vector<string> storage={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        std::string str="";
        digitt(0,digits,result,str,storage);
        return result;
    }
};