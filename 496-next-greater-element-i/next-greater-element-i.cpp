class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int,int> nextGreater;
        stack<int> st;
        for(int i = 0; i < nums2.size(); i++) {
            while(!st.empty() && nums2[i] > st.top()) {
                nextGreater[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }

        // For all remaining stack elements → no greater element
        while(!st.empty()) {
            nextGreater[st.top()] = -1;
            st.pop();
        }

        // Build result for nums1
        vector<int> result;
        for(int num : nums1) {
            result.push_back(nextGreater[num]);
        }

        return result;
    
/*
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
*/
    }
};