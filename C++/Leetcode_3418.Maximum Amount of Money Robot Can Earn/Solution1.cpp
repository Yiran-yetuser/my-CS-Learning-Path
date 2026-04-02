class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        vector<array<int, 3>> dp(n + 1,
                                 array<int, 3>{INT_MIN/2, INT_MIN/2, INT_MIN/2});
        // dp[x][y]代表在x列处，剩余y次感化机会
        dp[1] = {0, 0, 0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int val = coins[i][j];
                dp[j + 1][2] = max({dp[j][2] + val, dp[j + 1][2] + val,
                                    dp[j + 1][1], dp[j][1]});
                dp[j + 1][1] = max({dp[j][1] + val, dp[j + 1][1] + val,
                                    dp[j + 1][0], dp[j][0]});
                dp[j + 1][0] = max(dp[j][0] + val, dp[j + 1][0] + val);
            }
        }
        return dp[n][2];
    }
};
