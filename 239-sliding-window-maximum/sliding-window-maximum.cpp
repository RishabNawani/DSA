class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;

        for(int i=0; i<nums.size();i++){

            if(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);

            if(i>=k-1){
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
        /*
        int m = nums.size();
        int pairs = m-k+1;
        vector<int> storage;
        for(int i=0; i<pairs; i++){
            int maxx=nums[i];
            for(int j=i;j<=m-pairs+i;j++){
                maxx=max(maxx,nums[j]);
            }
            storage.push_back(maxx);
        }

        return storage;


        vector<int> st;
        int pt=0;
        while(pt<=(nums.size()-k)){
            int maxx=nums[pt];
            for(int i=pt;i<pt+k;i++){
                maxx=max(maxx,nums[i]);
            }
            st.push_back(maxx);
            pt++;
        }
        return st;

*/

        stack<int> st;
        int pt=0;
        while(pt<=(nums.size()-k)){
            int maxx=nums[pt];
            for(int i=pt;i<pt+k;i++){
                maxx=max(maxx,nums[i]);
            }
            st.push(maxx);
            pt++;
        }
        vector<int> stt;
        while(!st.empty()){
            stt.push_back(st.top());
        }

        std::reverse(stt.begin(),stt.end());

        return stt;
        
    }
};