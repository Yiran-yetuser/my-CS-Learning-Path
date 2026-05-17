class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int8_t> vis(n);

        auto dfs = [&](this auto&& dfs, int i) -> bool {
            if (i < 0 || i >= n || vis[i]) { // 出界，或者之前访问过（没找到）
                return false;
            }
            if (arr[i] == 0) { // 找到了
                return true;
            }
            vis[i] = true; // 避免重复访问
            return dfs(i + arr[i]) || dfs(i - arr[i]);
        };

        return dfs(start);
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/jump-game-iii/solutions/3960993/you-xiang-tu-dfspythonjavaccgojsrust-by-ju1jr/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
