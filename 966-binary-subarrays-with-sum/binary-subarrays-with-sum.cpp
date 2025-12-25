class Solution {
public:
/*
    int att(vector<int>& nums,int goal){
        if(goal<0) return 0;
        int i=0;
        int n=nums.size();
        int cnt=0;
        while(i<n){
            if(nums[i]==goal){
                cnt++;
                i++;
                continue;
            }
            else break;
        }

        if(cnt==n) return ((n)*(n+1))/2;

        int left=0;
        int count=0;
        int sum=0;
        for(int right=0;right<n;right++){
            sum+=nums[right];

            while(sum>goal){
                sum-=nums[left];
                left++;
            }

            count+=(right-left+1);
        }
        return count;

    }
    */
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        ///return (att(nums,goal)-att(nums,goal-1));

        unordered_map<int,int> summm;

        int count=0; int sum=0;
        summm[0]=1;

        for(int num:nums){
            sum+=num;

            if(summm.find(sum-goal)!=summm.end()){
                count+=summm[sum-goal];
            }

            summm[sum]++;
        }

        return count;
    }
};