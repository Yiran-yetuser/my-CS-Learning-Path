class Solution {
public:
    int numberOfSpecialChars(string word) {
        int lower = 0, upper = 0, invalid = 0;
        for (char c : word) {
            int bit = 1 << (c & 31);
            if (c & 32) { // 小写字母
                lower |= bit;
                if (upper & bit) { // c 也在 upper 中
                    invalid |= bit; // 不合法
                }
            } else { // 大写字母
                upper |= bit;
            }
        }
        // 从 lower 和 upper 的交集中去掉不合法的字母 invalid
        return popcount(1u * (lower & upper & ~invalid));
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/count-the-number-of-special-characters-ii/solutions/2749235/zhuang-tai-ji-on-yi-ci-bian-li-pythonjav-ajaz/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
