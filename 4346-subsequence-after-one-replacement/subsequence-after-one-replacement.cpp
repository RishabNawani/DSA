class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int i = 0, j = 0, n = s.length();
        for (char c : t) {
            j = max(j + (j < n && c == s[j] ? 1 : 0), i + 1);
            i += (i < n && c == s[i] ? 1 : 0);
        }
        return j >= n;
    }
};