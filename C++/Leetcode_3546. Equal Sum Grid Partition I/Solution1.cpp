class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long totalSum = 0;

        // 计算网格总和
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                totalSum += grid[i][j];
            }
        }

        // 如果总和是奇数，无法平分，剪枝
        if (totalSum % 2 != 0) {
            return false;
        }

        long long target = totalSum / 2;
        long long currentSum = 0;

        // 检查水平切割 (Horizontal Cut)
        // 切割线在第 i 行和第 i+1 行之间，所以遍历到 m-2 即可
        for (int i = 0; i < m; i++) {
            long long rowSum = 0;
            for (int j = 0; j < n; j++) {
                rowSum += grid[i][j];
            }
            currentSum += rowSum;
            // 如果当前累加和等于目标值，且不是最后一行（必须剩下至少一行）
            if (currentSum == target && i < m - 1) {
                return true;
            }
        }

        // 检查垂直切割 (Vertical Cut)
        currentSum = 0;
        for (int j = 0; j < n; j++) {
            long long colSum = 0;
            for (int i = 0; i < m; i++) {
                colSum += grid[i][j];
            }
            currentSum += colSum;
            // 如果当前累加和等于目标值，且不是最后一列
            if (currentSum == target && j < n - 1) {
                return true;
            }
        }

        return false;
    }
};
