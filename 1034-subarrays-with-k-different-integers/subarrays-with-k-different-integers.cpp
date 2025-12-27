class Solution {
public:

    int att(vector<int>& nums, int k){
        int left=0;
        int count=0;
        unordered_map<int,int> freqq;

        for(int right=0;right<nums.size();right++){
            if(freqq[nums[right]]==0){
                k--;
            }

            freqq[nums[right]]++;

            while(k<0){
                freqq[nums[left]]--;
                if(freqq[nums[left]]==0){
                    k++;
                }
                left++;
            }

            count+=(right-left+1);
        }

        return count;
    }


    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return (att(nums,k)-att(nums,k-1));
    }
};