class Solution {
public:
    void subsub(vector<int>& nums,vector<vector<int>>& ans){
        int n=nums.size();
        int size=1<<n;
        
        for(int i=0; i<size;i++){
            vector<int>subset;
            for(int j=0; j<n;j++){
                if(i & (1<<j)){
                    subset.push_back(nums[j]);
                }
            }
            ans.push_back(subset);
        }





    /*

        if(index==n){
            ressss.push_back(ress);
            return;
        }

        subsub(n,index+1,ress,ressss,nums);

        ress.push_back(nums[index]);

        subsub(n,index+1,ress,ressss,nums);

        ress.pop_back();
        */
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        /*
        int n=nums.size();
        int boundary = pow(2,n);
        vector<int> res;
        vector<vector<int>> result;
        subsub(n,0,res,result, nums);

        return result; 
        */
        vector<vector<int>> ans;
        subsub(nums,ans);
        return ans;
    }
};