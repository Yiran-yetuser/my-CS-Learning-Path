class Solution {
public:
    char findTheDifference(string s, string t) {
        // ASCII值暴力相加
        int lens = s.size();
        char result = 0;
        for(int i = 0;i<lens;i++) {
            result = result + t[i] - s[i];
        }
        result += t[lens];
        return result;
    }
};
