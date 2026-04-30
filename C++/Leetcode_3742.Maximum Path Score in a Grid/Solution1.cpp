class Solution {
    // 64. 最小路径和
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<int> f(n + 1, INT_MAX);
        f[1] = 0;
        for (auto& row : grid) {
            for (int j = 0; j < n; j++) {
                f[j + 1] = min(f[j], f[j + 1]) + min(row[j], 1); // 值大于 0 的单元格花费 1
            }
        }
        return f[n];
    }

public:
    int maxPathScore(vector<vector<int>>& grid, int K) {
        if (minPathSum(grid) > K) {
            return -1;
        }

        int m = grid.size(), n = grid[0].size();
        K = min(K, m + n - 2); // 至多花费 m+n-2
        vector f(n + 1, vector<int>(K + 2, INT_MIN));
        f[1][1] = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int x = grid[i][j];
                for (int k = min(K, i + j); k >= 0; k--) { // 从 (0,0) 到 (i,j) 至多花费 i+j
                    int new_k = k - (x > 0);
                    f[j + 1][k + 1] = max(f[j + 1][new_k + 1], f[j][new_k + 1]) + x;
                }
            }
        }

        return ranges::max(f[n]);
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/maximum-path-score-in-a-grid/solutions/3827073/wang-ge-tu-dppythonjavacgo-by-endlessche-myez/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
