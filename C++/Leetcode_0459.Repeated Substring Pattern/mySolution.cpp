class Solution {
public:
    bool kmp(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) {
            return true;
        }
        vector<int> pi(m);
        for (int i = 1, j = 0; i < m; i++) {
            while (j > 0 && needle[i] != needle[j]) {
                j = pi[j - 1];
            }
            if (needle[i] == needle[j]) {
                j++;
            }
            pi[i] = j;
        }
        for (int i = 0, j = 0; i < n; i++) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = pi[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == m) {
                return true;
            }
        }
        return false;
    }

    bool repeatedSubstringPattern(string s) {
        return kmp((s + s).substr(1, 2 * s.length() - 2), s);

        // 用.find似乎还更快一点，内置函数yyds
        // return (s + s).find(s, 1) != s.size();
    }
};
