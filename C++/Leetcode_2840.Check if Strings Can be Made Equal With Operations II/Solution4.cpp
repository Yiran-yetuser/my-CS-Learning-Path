class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int cnt1[2][26]{}, cnt2[2][26]{};
        for (int i = 0; i < s1.length(); i++) {
            cnt1[i % 2][s1[i] - 'a']++;
            cnt2[i % 2][s2[i] - 'a']++;
        }
        return memcmp(cnt1, cnt2, sizeof(cnt1)) == 0;
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/check-if-strings-can-be-made-equal-with-operations-ii/solutions/2424890/kan-xia-biao-wei-ou-shu-qi-shu-de-zi-fu-edtw8/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
