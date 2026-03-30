class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<array<int, 2>> a(26);
        for (int i = 0; i < s1.size(); i++) {
            int alpha1 = s1[i] - 'a';
            int alpha2 = s2[i] - 'a';
            a[alpha1][i % 2]++;
            a[alpha2][i % 2]--;
        }
        for (auto v : a) {
            if (v[0] != 0 || v[1] != 0) {
                return false;
            }
        }
        return true;
    }
};
