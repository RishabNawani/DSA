class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map <int , int> add;
        for (int i=0; i<n; i++){
            int num=nums[i];
            int left=target-num;
            if(add.find(left)!=add.end()){
                return {add[left],i};
            }
            add[num]=i;
        }  
        return {};     
    }
};