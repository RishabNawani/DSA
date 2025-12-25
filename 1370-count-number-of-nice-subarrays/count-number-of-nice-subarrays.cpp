class Solution {
public:
    int cntt(vector<int>& nums, int k){
        if(k<0) return 0;

        int left=0;
        int count=0;


        for(int right=0;right<nums.size();right++){
            if(nums[right]%2 !=0){
                k--;
            }
            
            while(k<0){
                if(nums[left]%2!=0){
                    k++;
                }
                left++;
            }

            count+=(right-left+1);
        }

        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return (cntt(nums,k)-cntt(nums,k-1));
    }
};