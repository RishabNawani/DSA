class Solution {
public:

    void targett(int index,vector<int>& res, vector<vector<int>>& result,vector<int>& arr, int target){
        if(target==0){
            result.push_back(res);
            return;
        }

        for(int i=index;i<arr.size();i++){
            if(i>index && arr[i]==arr[i-1]) continue;
            if(arr[i]>target)break;
            res.push_back(arr[i]);
            targett(i+1,res,result,arr,target-arr[i]);
            res.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int> ress;
        vector<vector<int>> ressult;
        sort(candidates.begin(),candidates.end());
        targett(0,ress,ressult,candidates,target);
        return ressult;
    }
};