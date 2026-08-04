class Solution {
public:

    int checkk(vector<int>& nums, int divi){
        int sum=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            sum+=ceil((double)nums[i]/(double)divi);
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        if(n>threshold) return -1;
        /*
        int mini=INT_MAX;
        for(int i=0; i<n; i++){
            int sum=0;
            for(int j=0; j<n; j++){
                sum+=ceil(nums[j]/nums[i]);
            }
            if(sum<=threshold){
                mini=nums[i];
                
            }
            else sum=0;
        }
        return mini;
        */
        int low=1, high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=(low+high)/2;
            if(checkk(nums,mid)<=threshold){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};