class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        for(int j=0;j<s.length();j++){
            bool matchh=true;
            for(int l=0; l<s.length(); l++){
                if(goal[(j+l)%s.length()]!= s[l]){
                    matchh=false;
                    break;
                }
            }
            if(matchh) return true;
        }
        return false;

/*my approach failed as i was taking into account the case in which each appears once for example abcde but what if more than one string appears , for example adbcbde, then it will fail.
        int k=0;
        int i=0;
        while(goal[i]!=s[0]){
            i++;
            k++;
        }
        int l=0;
        for(int j=0; j<s.length(); j++){
            if(goal[(k+l)%s.length()]!=s[j]) return false;
            l++;
        }
        return true;
*/
    }
};