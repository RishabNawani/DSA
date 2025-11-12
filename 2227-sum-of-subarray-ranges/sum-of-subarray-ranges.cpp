class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            int maxx=nums[i];
            int minn=nums[i];
            for(int j=i;j<nums.size();j++){
                maxx=max(nums[j],maxx);
                minn=min(nums[j],minn);
                sum+=maxx-minn;
            }
        }
        return sum;
    /*
        vector<vector<int>> sumarray;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                sumarray.push_back(std::vector<int>(nums.begin()+i,nums.begin()+j+1));
            }
        }

        for(int i=0;i<sumarray.size();i++){
            int max=INT_MIN;
            int min=INT_MAX;
            for(int val: sumarray[i]){
                max=max(val,max);
                min=min(val,min);
            }
            sum+=(long long)(max-min);
            
        }
        return sum;
    */
    }
};