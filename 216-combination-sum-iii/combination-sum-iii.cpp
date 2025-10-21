class Solution {
private: 
    void func(int n, int last, vector<int> &res, int k, vector<vector<int>> &result) {
        if(n==0 && res.size()==k){
            result.push_back(res);
            return;
        }

        if(n<=0 || res.size()>k){
            return;
        }

        for(int i=last; i<=9;i++){
            if(i<=n){
                res.push_back(i);

                func(n-i,i+1,res,k,result);

                res.pop_back();
            }
            else{break;}
        }
    } 
public:
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> res;
        vector<vector<int>> result;

        func(n,1,res,k,result);

        return result;

    }
};