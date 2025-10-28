class Solution {
public:
    int minBitFlips(int start, int goal) {
        string res="";
        while(start >0){
            int remainder=start%2;
            res+=remainder+'0';
            start=start/2;
        }
        std::reverse(res.begin(),res.end());

        string res2="";
        while(goal >0){
            int remainder=goal%2;
            res2+=remainder+'0';
            goal=goal/2;
        }
        std::reverse(res2.begin(),res2.end());
        int n=res.size();
        int m=res2.size();
        while(n>m){
            res2='0'+res2;
            m++;
        }
        while(n<m){
            res='0'+res;
            n++;
        }
        int cnt=0;

        for(int i=0;i<res.size();i++){
            if(res[i]!=res2[i]){
                cnt++;
            }
        }

        return cnt;
        
    }
};