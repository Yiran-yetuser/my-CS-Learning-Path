class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size(), m = walls.size();
        struct Pair { int x, d; };
        vector<Pair> a(n + 2);
        for (int i = 0; i < n; i++) {
            a[i] = {robots[i], distance[i]};
        }
        a[n + 1].x = INT_MAX;
        ranges::sort(a, {}, &Pair::x);
        ranges::sort(walls);

        int f0 = 0, f1 = 0, left = 0, cur = 0, right0 = 0, right1 = 0;
        for (int i = 1; i <= n; i++) {
            auto [x, d] = a[i];

            // 往左射，墙的坐标范围为 [left_x, x]
            int left_x = max(x - d, a[i - 1].x + 1); // +1 表示不能射到左边那个机器人
            while (left < m && walls[left] < left_x) {
                left++;
            }
            while (cur < m && walls[cur] < x) {
                cur++;
            }
            int cur1 = cur;
            if (cur < m && walls[cur] == x) {
                cur++;
            }
            int left_res = f0 + cur - left; // 下标在 [left, cur-1] 中的墙都能摧毁

            // 往右射，右边那个机器人往左射，墙的坐标范围为 [x, right_x]
            auto [x2, d2] = a[i + 1];
            int right_x = min(x + d, x2 - d2 - 1); // -1 表示不能射到右边那个机器人
            while (right0 < m && walls[right0] <= right_x) {
                right0++;
            }
            f0 = max(left_res, f1 + right0 - cur1); // 下标在 [cur1, right0-1] 中的墙都能摧毁

            // 往右射，右边那个机器人往右射，墙的坐标范围为 [x, right_x]
            right_x = min(x + d, x2 - 1); // -1 表示不能射到右边那个机器人
            while (right1 < m && walls[right1] <= right_x) {
                right1++;
            }
            f1 = max(left_res, f1 + right1 - cur1); // 下标在 [cur1, right1-1] 中的墙都能摧毁
        }
        return f1;
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/maximum-walls-destroyed-by-robots/solutions/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
