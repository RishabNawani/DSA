class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        for(int i=0;i<num.size();i++){
            while(!st.empty() && st.back()>num[i] && k>0){
                st.pop_back();
                k--;
            }
            st.push_back(num[i]);
        }

        while(k>0 && !st.empty()){
            st.pop_back();
            k--;
        }

        int ind=0;
        while(ind<st.size() && st[ind]=='0') ind++;

        string ans=st.substr(ind);
        if(ans.empty())return "0";
        else return ans;
    }
};