class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<array<int, 2>> a(26);
        for (int i = 0; i < s1.size(); i++) {
            a[s1[i] - 'a'][i % 2]++;
            a[s2[i] - 'a'][i % 2]--;
        }
        for (auto& v : a) {
            if (v[0]||v[1]) {
                return false;
            }
        }
        return true;
    }
};
