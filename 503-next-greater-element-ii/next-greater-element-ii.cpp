class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st; // store indices
        
        for (int i = 0; i < 2 * n; i++) {
            int num = nums[i % n];
            while (!st.empty() && nums[st.top()] < num) {
                res[st.top()] = num;
                st.pop();
            }
            if (i < n) st.push(i);
        }
        return res;
    /*
        vector<int> ress;
        for(int i=0; i<nums.size();i++){
            bool found=false;
            int num=nums[i];
            int add=-1;
            for(int j=i+1; j<nums.size()+i;j++){
                int ind=j%nums.size();
                if(nums[ind]>num){
                    add=nums[ind];
                    break;
                }
            }
            ress.push_back(add);
        }
        return ress;
        */
    }
};