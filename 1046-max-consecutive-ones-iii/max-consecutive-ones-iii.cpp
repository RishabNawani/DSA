class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int maxx=0;
        int zeros=0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]==0){
                zeros++;
            }
            while(zeros>k){
                if(nums[left]==0){
                    zeros--;
                }
                left++;
            }
            maxx=max(maxx,right-left+1);
        }
        return maxx;
        /*
        vector<int> zerr;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zerr.push_back(i);
        }
        int maxx=0;
        for(int i=0;i<zerr.size();i++){
            
            for(int j=0;j<k;j++){
            }
        }
        */
    }
};