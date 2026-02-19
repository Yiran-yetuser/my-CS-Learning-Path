class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        int count1 = 0, count2 = 0;
        char last = s[0];
        for (int i = 0; i <= s.size(); i++) {
            if (s[i] == last) {
                count1++;
            } else {
                ans += std::min(count1, count2);
                count2 = count1;
                count1 = 1;
                last = s[i];
            }
        }
        return ans;
    }
};
