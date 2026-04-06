class Solution {
    static constexpr int DIRS[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 上右下左（顺时针）

public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<int> obstacle_set;
        obstacle_set.reserve(obstacles.size()); // 预分配空间
        constexpr int OFFSET = 3e4;
        for (auto& p : obstacles) {
            // p 是两个 16 位整数，合并成一个 32 位整数
            obstacle_set.insert((p[0] + OFFSET) << 16 | (p[1] + OFFSET));
        }

        int ans = 0, x = 0, y = 0, k = 0;
        for (int c : commands) {
            if (c == -1) { // 右转
                k = (k + 1) % 4;
            } else if (c == -2) { // 左转
                k = (k + 3) % 4;
            } else { // 直行
                while (c--) {
                    int nx = x + DIRS[k][0];
                    int ny = y + DIRS[k][1];
                    if (obstacle_set.contains((nx + OFFSET) << 16 | (ny + OFFSET))) {
                        break;
                    }
                    x = nx;
                    y = ny;
                }
                ans = max(ans, x * x + y * y);
            }
        }
        return ans;
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/walking-robot-simulation/solutions/3937384/li-yong-xiang-liang-shu-zu-jian-hua-dai-s8s3d/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
