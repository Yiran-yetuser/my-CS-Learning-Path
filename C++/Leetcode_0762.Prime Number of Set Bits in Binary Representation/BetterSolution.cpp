class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int x = left; x <= right; ++x) {
            if ((1 << __builtin_popcount(x)) & 665772) {
                ++ans;
            }
        }
        return ans;
    }
};

作者：力扣官方题解
链接：https://leetcode.cn/problems/prime-number-of-set-bits-in-binary-representation/solutions/1389365/er-jin-zhi-biao-shi-zhong-zhi-shu-ge-ji-jy35g/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
