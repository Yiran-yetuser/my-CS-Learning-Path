class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        // 前缀和初始化每一列
        for (int j = 0; j < n; j++) {
            for (int i = 1; i < m; i++) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            sort(matrix[i].begin(), matrix[i].end(), greater<int>());

            // 计算当前行的最大面积
            for (int k = 0; k < n; k++) {
                if (matrix[i][k] == 0)
                    break; // 高度为 0 后续都为 0，可提前结束
                // 高度为 matrix[i][k]，宽度为 k + 1
                int area = matrix[i][k] * (k + 1);
                if (area > ans) {
                    ans = area;
                }
            }
        }

        return ans;
    }
};
