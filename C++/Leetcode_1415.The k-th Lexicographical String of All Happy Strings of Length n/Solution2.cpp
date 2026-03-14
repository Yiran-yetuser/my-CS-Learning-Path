class Solution {
public:
    string getHappyString(int n, int k) {
        if (k > 3 << (n - 1)) {
            return "";
        }
        k--; // 改成从 0 开始，方便计算
        string ans(n, 'a');
        ans[0] += k >> (n - 1);
        for (int i = 1; i < n; i++) {
            ans[i] += k >> (n - 1 - i) & 1;
            if (ans[i] >= ans[i - 1]) {
                ans[i]++;
            }
        }
        return ans;
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/solutions/3913970/on-jian-ji-xie-fa-pythonjavaccgojsrust-b-vxxs/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
