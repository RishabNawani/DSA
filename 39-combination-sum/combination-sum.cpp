class Solution {
public:
    void targett(int index,vector<int>& res, vector<vector<int>>& result,vector<int>& arr, int target){
        if(index==arr.size()){
            if(target==0){
                result.push_back(res);
            }
            return;
        }

        if(arr[index]<=target){
            res.push_back(arr[index]);
            targett(index,res,result,arr,target-arr[index]);
            res.pop_back();
        }

        targett(index+1,res,result,arr,target);

        

        
    }

    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int> ress;
        vector<vector<int>> ressult;
        targett(0,ress,ressult,candidates,target);

        return ressult;
    }
};