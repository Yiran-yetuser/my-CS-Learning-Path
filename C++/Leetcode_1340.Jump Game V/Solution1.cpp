class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        int ans = 1;          // 至少能访问 1 个下标（处理 n=1 的情况）
        vector<int> dp(n, 1); // 初始化为 1，每个点至少能访问自己
        vector<int> subscript(n);

        for (int i = 0; i < n; i++) {
            subscript[i] = i;
        }

        // 把下标按 arr 值升序排序
        sort(subscript.begin(), subscript.end(),
             [&](int x, int y) -> bool { return arr[x] < arr[y]; });

        for (int i = 0; i < n; i++) {
            int idx = subscript[i]; // 获取原数组的真实下标
            int maximum = 0;

            // 向左跳跃检查
            for (int k = idx - 1; k >= max(0, idx - d); k--) {
                if (arr[k] >= arr[idx])
                    break; // 遇到障碍物（高度 >= 当前点），停止向左
                maximum = max(maximum, dp[k]);
            }

            // 向右跳跃检查
            for (int k = idx + 1; k <= min(n - 1, idx + d); k++) {
                if (arr[k] >= arr[idx])
                    break; // 遇到障碍物（高度 >= 当前点），停止向右
                maximum = max(maximum, dp[k]);
            }

            // 使用真实下标 idx 更新 dp 和 ans
            dp[idx] = 1 + maximum;
            ans = max(ans, dp[idx]);
        }

        return ans;
    }
};
