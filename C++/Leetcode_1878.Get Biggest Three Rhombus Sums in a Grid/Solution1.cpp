class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> backwardSum(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> forwardSum(m + 1, vector<int>(n + 2, 0));

        // 初始化前缀和
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                backwardSum[i + 1][j + 1] = backwardSum[i][j] + grid[i][j];
                forwardSum[i + 1][j + 1] = forwardSum[i][j + 2] + grid[i][j];
            }
        }

        int first = 0, second = 0, third = 0;

        auto get = [&](int val) -> void {
            if (val > first) {
                third = second;
                second = first;
                first = val;
                return;
            }
            if (val > second && val != first) {
                third = second;
                second = val;
                return;
            }
            if (val > third && val != second && val != first) {
                third = val;
                return;
            }
        };

        // 遍历每个格子作为菱形中心
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                get(grid[i][j]);

                int maxLen = min({i, j, m - 1 - i, n - 1 - j});

                for (int len = 1; len <= maxLen; len++) {
                    // 四个顶点（0-indexed）
                    int top = i - len, bot = i + len;
                    int left = j - len, right = j + len;

                    // 计算四条边的和（每条边包含两个端点）
                    int sum = 0;

                    // 右上边 (Top -> Right) '\' 方向
                    sum += backwardSum[i + 1][right + 1] - backwardSum[top][j];

                    // 右下边 (Right -> Bottom) '/' 方向
                    sum +=
                        forwardSum[bot + 1][j + 1] - forwardSum[i][right + 2];

                    // 左下边 (Bottom -> Left) '\' 方向
                    sum += backwardSum[bot + 1][j + 1] - backwardSum[i][left];

                    // 左上边 (Left -> Top) '/' 方向
                    sum += forwardSum[i + 1][left + 1] - forwardSum[top][j + 2];

                    // 减去重复计算的 4 个顶点
                    sum -= grid[top][j] + grid[bot][j] + grid[i][left] +
                           grid[i][right];

                    get(sum);
                }
            }
        }

        // 构建结果
        vector<int> ans = {first, second, third};
        while (!ans.back()) {
            ans.pop_back();
        }
        return ans;
    }
};
