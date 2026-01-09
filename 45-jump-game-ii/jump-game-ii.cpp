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
       // return(minn(0,0,nums));
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

    }
};