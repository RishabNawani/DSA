class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size();
        int n=t.size();

        if(n>m) return "";

        

        int left=0;
        unordered_map<char,int> need;

        for(char c: t) need[c]++;

        int required = t.size();
        int minLen = INT_MAX, start = 0;
       
        for (int right = 0; right < s.size(); right++) {

            if (need[s[right]] > 0)
                required--;

            need[s[right]]--;

            // when window is valid
            while (required == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                need[s[left]]++;
                if (need[s[left]] > 0)
                    required++;

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);

    }
};