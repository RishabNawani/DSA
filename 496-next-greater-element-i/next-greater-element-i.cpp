class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int> result;
        for(int i=0;i<nums1.size();i++){
            bool found=false;
            int num=nums1[i];
            int add=-1;
            for(int j=0; j<nums2.size();j++){
                if(nums2[j]==num) found=true;
                if(found && nums2[j]>num){
                    add=nums2[j];
                    break;
                }
            }
            result.push_back(add); 
        }
        return result;
    }
};