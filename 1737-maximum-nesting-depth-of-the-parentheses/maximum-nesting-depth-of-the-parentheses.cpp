class Solution {
public:
    int maxDepth(string s) {
        int maxdepth=0;
        int depthcount=0;
        int lastcount=0;
        for(int i=0; i<s.size();i++){
            if (s[i]=='('){
                depthcount++;
            }
            else if(s[i]==')'){
                lastcount=depthcount;
                maxdepth=max(maxdepth,lastcount);
                depthcount--;
            }
        }
        return maxdepth;
    }
};