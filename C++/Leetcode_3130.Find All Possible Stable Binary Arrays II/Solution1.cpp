class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1'000'000'007;
        // zero 和 one 各多取一位，防止状态转移方程中数组越界
        vector<vector<array<int, 2>>> dp(zero + 1,
                                         vector<array<int, 2>>(one + 1));
        for (int i = 1; i <= min(zero, limit); i++) {
            dp[i][0][0] = 1;
        }
        for (int j = 1; j <= min(one, limit); j++) {
            dp[0][j][1] = 1;
        }
        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {
                dp[i][j][0] =
                    ((long long)dp[i - 1][j][1] + dp[i - 1][j][0] + MOD -
                     (i <= limit ? 0 : dp[i - 1 - limit][j][1])) %
                    MOD;
                dp[i][j][1] =
                    ((long long)dp[i][j - 1][1] + dp[i][j - 1][0] + MOD -
                     (j <= limit ? 0 : dp[i][j - 1 - limit][0])) %
                    MOD;
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};
