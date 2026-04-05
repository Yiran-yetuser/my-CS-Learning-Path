class Solution {
public:
    bool judgeCircle(string moves) {
        return ranges::count(moves, 'R') == ranges::count(moves, 'L') &&
               ranges::count(moves, 'U') == ranges::count(moves, 'D');
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/robot-return-to-origin/solutions/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
