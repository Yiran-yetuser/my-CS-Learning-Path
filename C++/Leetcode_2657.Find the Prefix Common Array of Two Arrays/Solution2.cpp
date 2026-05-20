class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        uint64_t p = 0, q = 0;
        for (int i = 0; i < a.size(); i++)
        {
            p |= 1ULL << a[i];
            q |= 1ULL << b[i];
            a[i] = popcount(p & q);
        }
        return a;
    }
};

// 作者：iqwqi
// 链接：https://leetcode.cn/problems/find-the-prefix-common-array-of-two-arrays/solutions/3971300/c-bao-li-wei-yun-suan-cpp-by-iqwqi-oetk/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
