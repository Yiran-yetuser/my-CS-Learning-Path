class Solution {

public:
    // 顺时针旋转矩阵90°

    vector<vector<int>> rotate(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size();
        vector<vector<int>> b(n, vector<int>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                b[j][m - 1 - i] = a[i][j];
            }
        }
        return b;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long totalSum = 0;
        for (auto& row : grid) {
            for (auto& x : row) {
                totalSum += x;
            }
        }

        // 判断竖直切割
        auto check = [&](vector<vector<int>> g) -> bool {
            int m = g.size(), n = g[0].size();
            if (n == 1) {
                return false;
            } // 仅有一列，直接返回false

            unordered_set<long long> hashSet = {0}; // 提前存入0
            long long sum = 0;
            for (int j = 0; j < n - 1; j++) {
                for (int i = 0; i < m; i++) {
                    sum += g[i][j];
                    hashSet.insert(g[i][j]);
                }

            long long target = 2 * sum - totalSum; // target用long long溢出
                // 特殊情况处理
                if (target == 0) {
                    return true;
                } // 差值为0，一定可分，直接返回true
                if (hashSet.find(target) != hashSet.end()) {
                    if (m == 1 && g[0][0] != target && g[0][j] != target) {
                        continue;
                    }
                    if (j == 0 && g[0][0] != target && g[m - 1][0] != target) {
                        continue;
                    }
                    return true;
                }
            }
            return false;
        };
        auto a = rotate(grid);
        auto b = rotate(a);
        auto c = rotate(b);
        return check(grid) || check(a) || check(b) || check(c);
    }
};
