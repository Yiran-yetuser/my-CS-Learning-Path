class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<int> left(n), right(n);
        unordered_map<int, int> first, last; // 记录首次出现和最后一次出现的位置
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            left[i] = last.contains(x) ? last[x] : -1;
            if (left[i] >= 0) {
                right[left[i]] = i;
            }
            if (!first.contains(x)) {
                first[x] = i;
            }
            last[x] = i;
        }

        for (int& i : queries) {
            int l = left[i] >= 0 ? left[i] : last[nums[i]] - n;
            if (i - l == n) {
                i = -1;
            } else {
                int r = right[i] ? right[i] : first[nums[i]] + n;
                i = min(i - l, r - i);
            }
        }
        return queries;
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/closest-equal-element-queries/solutions/3613906/er-fen-cha-zhao-jian-ji-xie-fa-pythonjav-516v/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
