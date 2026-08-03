class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int XOR=0;
        for(int i=0; i<nums.size();i++){
            XOR^=nums[i];
        }
        return XOR;

        /*
        int n=nums.size();
        std::sort(nums.begin(),nums.end());
        int dogla=0;
        if(n==1){
            dogla=nums[0];
        }
        else if(nums[0]!=nums[1]){
            dogla=nums[0];
        }
        else if(nums[n-2]!=nums[n-1]){
            dogla=nums[n-1];
        }
        for(int i=1; i<n-1; i++){
            if(nums[i]!=nums[i+1] && nums[i]!=nums[i-1] ){
                dogla=nums[i];
                break;
            }
        }
        return dogla;
        */
    }
};