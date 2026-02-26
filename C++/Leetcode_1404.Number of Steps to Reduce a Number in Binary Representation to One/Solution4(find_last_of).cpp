class Solution {
public:
    int numSteps(string s) {
        int ans = s.size() - 1;
        int i = s.find_last_of('1');
        if (i > 0) {
            ans += count(s.begin() + 1, s.begin() + i, '0') + 2;
        }
        return ans;
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/solutions/3903881/liang-chong-fang-fa-mo-ni-jian-ji-gong-s-dtlf/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
