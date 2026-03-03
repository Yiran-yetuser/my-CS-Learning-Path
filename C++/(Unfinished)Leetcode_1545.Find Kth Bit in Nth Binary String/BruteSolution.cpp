class Solution {
public:
    void invert(string &s) {
        for (int i = 0; i < s.size(); i++) {
            s[i] = (s[i] == '1' ? '0' : '1');
        }
    }
    char findKthBit(int n, int k) {
        vector<string> s(n + 1);
        s[1] = "0";
        for (int i = 2; i <= n; i++) {
            s[i] = s[i - 1] + "1";
            invert(s[i - 1]);
            reverse(s[i - 1].begin(), s[i - 1].end());
            s[i] = s[i] + s[i-1];
        }
        return s[n][k-1];
    }
};
