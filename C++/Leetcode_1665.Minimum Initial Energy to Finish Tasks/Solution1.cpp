class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        ranges::sort(tasks, {}, [](auto& t) { return t[0] - t[1]; });

        int ans = 0;
        int s = 0; // 累计耗费的能量之和
        for (auto& t : tasks) {
            int actual = t[0], minimum = t[1];
            // 题目要求 E0 - s >= minimum，即 E0 >= s + minimum
            // 由此可以得到 n 个 E0 的下界，所有下界的最大值即为答案
            ans = max(ans, s + minimum);
            s += actual;
        }
        return ans;
    }
};
