class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // colX[j] 存储第 j 列到当前行 i 为止的 'X' 的垂直总和
        // colY[j] 存储第 j 列到当前行 i 为止的 'Y' 的垂直总和
        vector<int> colX(m, 0);
        vector<int> colY(m, 0);

        int ans = 0;

        for (int i = 0; i < n; ++i) {
            int row_sum_x = 0; // 当前行从 0 列到 j 列的 X 累计（即子矩阵 (0,0)
                               // 到 (i,j) 的 X 总数）
            int row_sum_y = 0; // 当前行从 0 列到 j 列的 Y 累计

            for (int j = 0; j < m; ++j) {
                // 更新前缀和
                if (grid[i][j] == 'X') {
                    colX[j] += 1;
                }
                if (grid[i][j] == 'Y') {
                    colY[j] += 1;
                }

                // 统计列和（累加当前列的垂直前缀和，得到矩形区域内的总和）
                row_sum_x += colX[j];
                row_sum_y += colY[j];

                // 如果区域内 X 和 Y 的数量相等且大于 0，则计数
                if (row_sum_x == row_sum_y && row_sum_x > 0) {
                    ans += 1;
                }
            }
        }

        return ans;
    }
};
