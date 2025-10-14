class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int pref=1,suff=1;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            if(pref==0) pref=1;
            if(suff==0) suff=1;
    
            pref*=nums[i];
            suff*=nums[n-i-1];
            ans=max(ans,max(pref,suff));
        }
        return ans;



        /*
        int maxProd = nums[0];
        int currMax = nums[0];
        int currMin = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0)
                swap(currMax, currMin);
            
            currMax = max(nums[i], currMax * nums[i]);
            currMin = min(nums[i], currMin * nums[i]);

            maxProd = max(maxProd, currMax);
        }
        return maxProd;
        */
    }
};
