class Solution {
public:
    int minFlips(string s) {
        int n = s.size(), ans = n, cnt = 0;
        for (int i = 0; i < n * 2 - 1; i++) {
            cnt += (s[i % n] ^ i) & 1;
            int left = i - n + 1;
            if (left < 0) {
                continue;
            }
            ans = min({ans, cnt, n - cnt});
            cnt -= (s[left] ^ left) & 1;
        }
        return ans;
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/solutions/815298/cong-qian-wang-hou-pi-pei-cong-hou-wang-uiq6a/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
