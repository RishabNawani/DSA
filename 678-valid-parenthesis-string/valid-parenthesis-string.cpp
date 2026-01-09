class Solution {
public:
    bool checkValidString(string s) {
        int minnn=0;
        int maxxx=0;

        for(char c: s){
            if(c=='('){
                minnn++;
                maxxx++;
            }
            else if(c==')'){
                minnn--;
                maxxx--;
            }

            else{
                minnn--;
                maxxx++;
            }

            if(maxxx<0) return false;

            minnn=max(minnn,0);
        }

        if(minnn>0) return false;
        return true;

































        /*
        int minn=0;
        int maxx=0;


        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                minn++;
                maxx++;
            }
            else if(s[i]==')'){
                minn--;
                maxx--;
            }
            else{
                minn--;
                maxx++;
            }

            if(maxx<0) return false;

            minn=max(0,minn);
        }
    
        if(minn>0)return false;
        return true;
        */
    }
};