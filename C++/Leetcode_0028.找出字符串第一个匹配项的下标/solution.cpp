class Solution {
public:
    int strStr(string haystack, string needle) {
        // 用内置函数库，没什么意思而且时间复杂度有点大（暴力查找）
        /*
        int pos = haystack.find(needle);
        if(std::string::npos == pos)
            return -1;
        else
            return pos;
            */

        // 手搓一个差不多的 暴力查找
        /*
        int index = 0;
        int i = 0, j = 0;
        while (i < haystack.size()) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                j = 0;
                index++;
                i = index;
            }
            if (j == needle.size())
                return index;
        }
        return -1;
        */

        // kmp算法
        int n = haystack.size(), m = needle.size();
        if (m == 0) {
            return 0;
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
                return i - m + 1;
            }
        }
        return -1;

    }
};
