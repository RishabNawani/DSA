class Solution {
public:
    int numberOfSubstrings(string s) {
        if(s.size()<3) return 0;
        int cnt=0;
        vector<int> lastt(3,0);
        int left=0;
        for(int i=0;i<s.size();i++){
            lastt[s[i]-'a']++;
            while(lastt[0]>0 && lastt[1]>0 && lastt[2]>0 ){
                cnt+=s.size()-i;

                lastt[s[left]-'a']--;
                left++;
            }
        }

        return cnt;
    }
};