class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int x = nums[i];
            while (x > 0) {
                res.push_back(x % 10);
                x /= 10;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/separate-the-digits-in-an-array/solutions/3963822/fen-ge-shu-zu-zhong-shu-zi-de-shu-wei-by-540c/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
