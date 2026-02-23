class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < (1 << k) + k - 1) {
            return false;
        }
        std::unordered_set<string> substring;
        for (int i = 0; i + k <= s.size(); i++) {
            substring.insert(s.substr(i, k));
        }
        return substring.size() == (1 << k);
    }
};
