class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD = 12345;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n));

        long long suffix = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                res[i][j] = suffix;
                suffix = suffix * grid[i][j] % MOD;
            }
        }
        long long prefix = 1;
        for (int i = 0; i <= m - 1; i++) {
            for (int j = 0; j <= n - 1; j++) {
                res[i][j] = res[i][j] * prefix % MOD;
                prefix = prefix * grid[i][j] % MOD;
            }
        }
        return res;
    }
};
