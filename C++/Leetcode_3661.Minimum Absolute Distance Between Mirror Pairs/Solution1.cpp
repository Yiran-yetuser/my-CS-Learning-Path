class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> last;
        int ans = n;
        for (int i = 0; i < n; i++) {
            auto it = last.find(nums[i]);
            if (it != last.end()) {
                int dist = i - it->second;
                if (dist < ans) {
                    ans = dist;
                }
                if (ans == 1) {
                    return 1;
                }
            }
            int rev = 0, tmp = nums[i];
            while (tmp > 0) {
                rev = rev * 10 + tmp % 10;
                tmp /= 10;
            }
            last[rev] = i;
        }
        return ans == n ? -1 : ans;
    }
};
