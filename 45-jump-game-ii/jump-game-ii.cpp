class Solution {
public:
/*
    int minn(int ind , int jumpp,vector<int>& nums){
        if(ind>=nums.size()-1) return jumpp;
        int mini=INT_MAX;
        for(int j=1;j<=nums[ind];j++){
            mini=min(mini,minn(ind+j,jumpp+1,nums));
        }
        return mini;
    }
*/
    int jump(vector<int>& nums) {
        int jumpp=0;
        int far=0;
        int curr=0;

        for(int i=0;i<nums.size()-1;i++){
            far=max(far,i+nums[i]);

            if(i==curr){
                jumpp++;
                curr=far;
            }

        }

        return jumpp;







       /* return(minn(0,0,nums));
        int jumpp=0;
        int l=0;
        int r=0;
        for(int i=0;i<nums.size()-1;i++){
            r=max(r,i+nums[i]);
            if(i==l){
                jumpp++;

                l=r;
            }
        }
        return jumpp;
        */
    }
};