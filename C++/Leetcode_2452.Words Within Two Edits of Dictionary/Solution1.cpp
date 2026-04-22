class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for (auto& q : queries) {
            for (auto& s : dictionary) {
                int cnt = 0;
                for (int i = 0; i < s.size() && cnt <= 2; i++) {
                    if (q[i] != s[i]) {
                        cnt++;
                    }
                }
                if (cnt <= 2) {
                    ans.push_back(q);
                    break;
                }
            }
        }
        return ans;
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/words-within-two-edits-of-dictionary/solutions/1935782/bao-li-mei-ju-by-endlesscheng-afko/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
