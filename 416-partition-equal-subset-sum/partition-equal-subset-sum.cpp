class Solution {
public:
    bool subb(vector<int> &nums,int target, int n){
        vector<bool> prev(target+1,0), cur(target+1,0);
        prev[0]=cur[0]=true;
        if(nums[0]<=target) prev[nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                bool nottake= prev[j];
                bool take=false;
                if(nums[i]<=j) take=prev[j-nums[i]];
                cur[j]= take| nottake;
            }
            prev=cur;
        }

        return prev[target];
    }


    bool canPartition(vector<int>& nums) {
        int totsum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            totsum+=nums[i];
        }
        if(totsum%2==1) return false;
        int target=totsum/2;
        return subb(nums,target,n);
    }
};