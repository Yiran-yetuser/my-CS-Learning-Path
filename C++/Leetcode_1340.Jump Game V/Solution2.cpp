class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();

        // 计算 arr[i] 左边最近的更大元素 arr[left[i]]
        vector<int> left(n);
        vector<int> st;
        for (int i = 0; i < n; i++) {
            int x = arr[i];
            while (!st.empty() && arr[st.back()] <= x) {
                st.pop_back();
            }
            // 如果左边没有更大的数，或者跳跃距离超过 d，都标记为 -1
            left[i] = st.empty() || i - st.back() > d ? -1 : st.back();
            st.push_back(i);
        }

        // 计算 arr[i] 右边最近的更大元素 arr[right[i]]
        vector<int> right(n);
        st.clear();
        for (int i = n - 1; i >= 0; i--) {
            int x = arr[i];
            while (!st.empty() && arr[st.back()] <= x) {
                st.pop_back();
            }
            // 如果右边没有更大的数，或者跳跃距离超过 d，都标记为 -1
            right[i] = st.empty() || st.back() - i > d ? -1 : st.back();
            st.push_back(i);
        }

        vector<int> memo(n);

        auto dfs = [&](this auto&& dfs, int i) -> int {
            if (i < 0) { // 没有更大的数，或者跳跃距离超过 d
                return 0;
            }
            int& res = memo[i];
            if (res == 0) { // 没有计算过
                // 往左跳 vs 往右跳
                res = max(dfs(left[i]), dfs(right[i])) + 1;
            }
            return res;
        };

        // 枚举终点，倒着跳
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(i));
        }
        return ans;
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/jump-game-v/solutions/3963787/liang-chong-fang-fa-zheng-zhao-tiao-dao-pl5ep/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
