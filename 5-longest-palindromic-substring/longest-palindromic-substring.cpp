class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int startt=0;
        int len=1;

        for(int i=1; i<n;i++){
            
            int low=i-1;
            int high=i+1;
            while((low>=0 && high<n) && s[low]==s[high]){
                if(high-low+1>len){
                    startt=low;
                    len=high-low+1;
                }
                low--, high++;
            }
            
            
            low=i;
            high=i-1;
            while((low>=0 && high<n) && s[low]==s[high]){
                if(high-low+1>len){
                    startt=low;
                    len=high-low+1;
                }
                low--, high++;
            }
            
        }
        return s.substr(startt,len);
    }
};