class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ress;
        for(int i=0; i<nums.size();i++){
            bool found=false;
            int num=nums[i];
            int add=-1;
            for(int j=i+1; j<nums.size()+i;j++){
                int ind=j%nums.size();
                if(nums[ind]>num){
                    add=nums[ind];
                    break;
                }
            }
            ress.push_back(add);
        }
        return ress;
    }
};