class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1'000'000'007;
        vector<vector<array<int, 2>>> f(zero + 1, vector<array<int, 2>>(one + 1));
        for (int i = 1; i <= min(limit, zero); i++) {
            f[i][0][0] = 1;
        }
        for (int j = 1; j <= min(limit, one); j++) {
            f[0][j][1] = 1;
        }
        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {
                // + MOD 保证答案非负
                f[i][j][0] = ((long long) f[i - 1][j][0] + f[i - 1][j][1] + (i > limit ? MOD - f[i - limit - 1][j][1] : 0)) % MOD;
                f[i][j][1] = ((long long) f[i][j - 1][0] + f[i][j - 1][1] + (j > limit ? MOD - f[i][j - limit - 1][0] : 0)) % MOD;
            }
        }
        return (f[zero][one][0] + f[zero][one][1]) % MOD;
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/find-all-possible-stable-binary-arrays-ii/solutions/2758868/dong-tai-gui-hua-cong-ji-yi-hua-sou-suo-37jdi/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
