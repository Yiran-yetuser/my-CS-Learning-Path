class Solution {
    static const int MOD = 1e9 + 7;

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for (const auto& q : queries) {
            int idx = q[0], r = q[1], k = q[2], v = q[3];
            while (idx <= r) {
                nums[idx] = (long long)nums[idx] * v % MOD;
                idx += k;
            }
        }
        int ans = 0;
        for (const auto& x : nums) {
            ans ^= x;
        }
        return ans;
    }
};
