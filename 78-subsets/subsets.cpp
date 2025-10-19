class Solution {
public:
    void subsub(int n,int index, vector<int>& ress,vector<vector<int>>& ressss,vector<int>& nums){
    
        if(index==n){
            ressss.push_back(ress);
            return;
        }

        subsub(n,index+1,ress,ressss,nums);

        ress.push_back(nums[index]);

        subsub(n,index+1,ress,ressss,nums);

        ress.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int boundary = pow(2,n);
        vector<int> res;
        vector<vector<int>> result;
        subsub(n,0,res,result, nums);

        return result;
    }
};