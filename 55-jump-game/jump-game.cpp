class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jumpp=0;

        for(int i=0;i<nums.size();i++){

            if(i>jumpp) return false;

            jumpp=max(jumpp,i+nums[i]);

        }

        return true;
    }
};