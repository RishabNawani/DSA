class Solution {
public:
    int robb(vector<int>& nums,int i,vector<int>& dp){
        if(i<0) return 0;
        if(i==0) return nums[0];
        if(dp[i]!=-1) return dp[i];

        int pickk=nums[i]+robb(nums,i-2,dp);
        int notpickk=robb(nums,i-1,dp);

        return dp[i]=max(pickk,notpickk);
    }

    int rob(vector<int>& nums) {
        /*
        TABULATION METHOD

        int n=nums.size();

        if(n==1) return nums[0];
        vector<int> dp(n);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }      

        return dp[n-1];
        */

        /* Memoization method*/

        int n=nums.size();
        vector<int> dp(n,-1);
        return robb(nums,n-1,dp);
    }
};