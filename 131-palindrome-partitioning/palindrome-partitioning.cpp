class Solution {
public:
    bool pali(string &s,int index, int i){
        while(index<i){
            if (s[index]!=s[i]) return false;

            index++;
            i--;
        }
        return true;
    }


    void stringg(string &s , int index, vector<string> &res, vector<vector<string>> &result,string str){
        if(index==s.size()){
            result.push_back(res);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(pali(s,index,i)){
                str=s.substr(index,i-index+1);
                res.push_back(str);

                stringg(s,i+1,res,result,str);

                res.pop_back();

            }
        }

    }

    vector<vector<string>> partition(string s) {
        vector<string> res;
        vector<vector<string>> result;
        stringg(s,0,res,result,"");
        return result;
    }
};