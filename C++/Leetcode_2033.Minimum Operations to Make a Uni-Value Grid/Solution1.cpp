class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();
        vector<int> factor(m * n); // 每个元素除以a
        int remainder = grid[0][0] % x;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] % x != remainder) {
                    return -1;
                }
                factor[i * n + j] = grid[i][j] / x;
            }
        } // 初始化factor
        sort(factor.begin(), factor.end());
        int median = factor[factor.size() / 2];
        int ans = 0;
        for (auto& f : factor) {
            ans += abs(f - median);
        }
        return ans;
    }
};
