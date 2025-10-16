class Solution {
public:
    int nummm(const string& s,int i,long long num,int sign){
        if(i>s.size() || !isdigit(s[i])){
            return (int)(sign*num);
        }

        num=num*10+(s[i]-'0');

        if(sign*num>=INT_MAX) return INT_MAX;
        if(sign*num<=INT_MIN) return INT_MIN;

        return nummm(s,i+1,num,sign);
    }
    int myAtoi(string s) {
        int i=0, n=s.size();
        long result=0;
        int sign=1;

        while(i<n && s[i]==' '){
            i++;
        }

        if(i<n && (s[i]=='+' || s[i]=='-')){
            if(s[i]=='-'){
                sign= -1;
            }
            i++;
        }
        return nummm(s,i,0,sign);

        /*

        while(i<n && isdigit(s[i])){
            result=result*10+(s[i]-'0');

            if(sign*result>INT_MAX) return INT_MAX;
            if(sign*result<INT_MIN) return INT_MIN;
            i++;
        }

        return (int)(sign*result);
*/
    }
};