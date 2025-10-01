class Solution {
public:
    string reverseWords(string s) {
        /*
        int a=s.length();
        std::string ans="";
        std::reverse(s.begin(),s.end());

        for(int i=0; i<a; i++){
            std::string word="";
            while(i<a && s[i]!=' '){
                word+=s[i];
                i++;
            }
            std::reverse(word.begin(),word.end());
            if(word.length()>0) ans+=" "+word;;
        }
        return ans.substr(1);
*/

        
        int left =0;
        int right=s.length()-1;
        std::string temp= "";
        std::string ans= "";
        while(left<=right){
            char c=s[left];
            if(c!=' ') temp+=c;
            else if(c==' '){
                if(ans!="" && temp!="") ans=temp+" "+ans;
                else if(ans!="" && temp=="") ans=temp+""+ans;
                else ans=temp;
                temp="";
            }
            left++;
        }
        if(temp!=""){
            if(ans!="") ans=temp+" "+ans;
            else ans=temp;
            temp="";
        }
        return ans;
    }
};