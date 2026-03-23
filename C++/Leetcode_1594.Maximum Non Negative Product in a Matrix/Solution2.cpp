class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<long long> f_min(n), f_max(n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                long long x = grid[i][j];
                if (i == 0 && j == 0) {
                    f_min[0] = f_max[0] = x;
                    continue;
                }

                long long res_min = LLONG_MAX;
                long long res_max = LLONG_MIN;
                if (i > 0) {
                    long long mn = f_min[j], mx = f_max[j];
                    res_min = min(mn * x, mx * x);
                    res_max = max(mn * x, mx * x);
                }
                if (j > 0) {
                    long long mn = f_min[j - 1], mx = f_max[j - 1];
                    res_min = min(res_min, min(mn * x, mx * x));
                    res_max = max(res_max, max(mn * x, mx * x));
                }

                f_min[j] = res_min;
                f_max[j] = res_max;
            }
        }

        long long ans = f_max[n - 1];
        return ans < 0 ? -1 : ans % 1'000'000'007;
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/maximum-non-negative-product-in-a-matrix/solutions/3923633/ji-yi-hua-sou-suo-di-tui-kong-jian-you-h-hz2m/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
