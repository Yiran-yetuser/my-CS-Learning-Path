class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        vector<int> heights(n);
        vector<int> idx(n); // 按照高度排序后的列号
        ranges::iota(idx, 0); // idx[i] = i
        vector<int> non_zeros(n); // 避免在循环内反复申请内存
        int ans = 0;

        for (auto& row : matrix) {
            int p = 0, q = 0;
            for (int j : idx) {
                if (row[j] == 0) {
                    heights[j] = 0;
                    idx[p++] = j; // 高度 0 排在前面
                } else {
                    heights[j]++;
                    non_zeros[q++] = j;
                }
            }

            // heights[idx[i]] 是递增的
            for (int i = p; i < n; i++) { // 高度 0 无需计算
                idx[i] = non_zeros[i - p]; // 把 non_zeros 复制到 idx 的 [p,n-1] 中
                ans = max(ans, (n - i) * heights[idx[i]]);
            }
        }

        return ans;
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/largest-submatrix-with-rearrangements/solutions/3920921/mei-ju-zi-ju-xing-de-di-bian-omn-you-hua-dfy3/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
