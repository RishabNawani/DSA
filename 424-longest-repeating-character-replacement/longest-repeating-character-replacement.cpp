class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int maxx=0;
        int maxfreq=0;
        unordered_map<char,int> freqq;
        for (int right=0;right<s.size();right++){
            freqq[s[right]]++;
            maxfreq=max(maxfreq,freqq[s[right]]);

            while((right-left+1)-maxfreq>k){
                freqq[s[left]]--;
                left++;
            }

            maxx=max(maxx,right-left+1);
        }
        return maxx;
    }
};