class Solution {
public:
    bool checkStrings(const string& s1, const string& s2) {
        if (s1.size() != s2.size()) return false;
        
        int cnt[52] = {};
        const char* p1 = s1.data();
        const char* p2 = s2.data();
        int n = s1.size();
        
        for (int i = 0; i < n; ++i) {
            cnt[(p1[i] - 97) * 2 + (i & 1)]++;  // 97 = 'a'
            cnt[(p2[i] - 97) * 2 + (i & 1)]--;
        }
        
        // memcmp 高度优化，使用 SIMD 指令
        static const int zero[52] = {};
        return memcmp(cnt, zero, sizeof(cnt)) == 0;
    }
};
