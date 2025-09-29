class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        int n=nums.size();
        int count=1;
        int prevcount=1;
        if(n==1) return 1;
        if(n==0) return 0;
        for(int i=0; i<n; i++){
            if(i!=n-1){
                if (nums[i+1] == nums[i]) {
                    continue;
                }
                if(nums[i+1]-nums[i]==1){
                    count++;
                }
                else{
                    count=1;
                }
                prevcount=max(prevcount,count);
            } 
        }
        return prevcount;
    }
};