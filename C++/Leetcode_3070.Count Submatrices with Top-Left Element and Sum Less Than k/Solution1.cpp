class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // 计算二维前缀和：P[i][j] = val + P[i-1][j] + P[i][j-1] - P[i-1][j-1]
                int up = (i > 0) ? grid[i - 1][j] : 0;
                int left = (j > 0) ? grid[i][j - 1] : 0;
                int diag = (i > 0 && j > 0) ? grid[i - 1][j - 1] : 0;
                
                grid[i][j] = grid[i][j] + up + left - diag;

                // 判断当前子矩阵和是否满足条件
                if (grid[i][j] <= k) {
                    ans++;
                } else {
                    // 优化点 1：假设元素非负，若当前和 > k，则该行右侧后续前缀和必然 > k
                    break; 
                }
            }
            // 优化点 2：如果该行第一个元素就 > k，说明第一列前缀和已超标
            // 由于元素非负，后续所有行的第一列前缀和只会更大，可直接结束
            if (n > 0 && grid[i][0] > k) {
                break;
            }
        }
        return ans;
    }
};
