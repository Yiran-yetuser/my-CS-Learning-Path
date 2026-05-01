class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int F0 = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            F0 += i * nums[i];
        }
        int ans = F0;
        for (int i = n - 1; i > 0; i--) {
            F0 = F0 + sum - n * nums[i];
            ans = max(ans, F0);
        }
        return ans;
    }
};
