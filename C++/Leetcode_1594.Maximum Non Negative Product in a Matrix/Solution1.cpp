class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        long long MOD = 1e9 + 7;
        bool haveZero = false;
        if (grid[0][0] == 0) {
            return 0;
        }
        int m = grid.size(), n = grid[0].size();
        vector<array<long long, 2>> dp(n);

        if (grid[0][0] > 0) {
            dp[0][1] = grid[0][0];
        } else {
            dp[0][0] = grid[0][0];
        }
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                long long negUp = j > 0 ? dp[i][0] : 0;
                long long posUp = j > 0 ? dp[i][1] : 0;
                long long negLeft = i > 0 ? dp[i - 1][0] : 0;
                long long posLeft = i > 0 ? dp[i - 1][1] : 0;
                long long neg = min(negLeft, negUp);
                long long pos = max(posLeft, posUp);
                long long val = grid[j][i];
                if (val == 0) {
                    haveZero = true;
                }
                if (val < 0) {
                    dp[i][0] = val * pos;
                    dp[i][1] = val * neg;
                } else {
                    dp[i][1] = val * pos;
                    dp[i][0] = val * neg;
                }
            }
        }
        if (dp[n - 1][1] == 0 && haveZero == false) {
            return -1;
        }
        return dp[n - 1][1] % MOD;
    }
};
