class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) {
            return 1;
        }
        int w = bit_width((uint32_t) n);
        return ((1 << w) - 1) ^ n;
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/complement-of-base-10-integer/solutions/3921125/ku-han-shu-xie-fa-pythonjavaccgojsrust-b-n232/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
