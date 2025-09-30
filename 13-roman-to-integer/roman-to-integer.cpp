class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> freqq={
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
        };
        int result=0;
        int n=s.size();
        for(int i=0; i<n; i++){
            if(i<n-1 && freqq[s[i]]<freqq[s[i+1]]){
                result-=freqq[s[i]];
            }
            else{
                result+=freqq[s[i]];
            }
        }
        return result;
        
               
    }
};