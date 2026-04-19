class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1), hash(n);
        int maxi=1;
        int lastt=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }

            if(dp[i]>maxi){
                maxi=dp[i];
                lastt=i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[lastt]);
        while(lastt!=hash[lastt]){
            lastt=hash[lastt];
            ans.push_back(nums[lastt]);
        }
        return ans;

    }
};