class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int len = nums.size();
        int delta = nums[len - 1] - nums[0];
        if (delta == 0) {
            for (int i = 0; i < len - 1; i++) {
                if (nums[i] != nums[i + 1]) {
                    return false;
                }
            }
        } else if (delta > 0) {
            for (int i = 0; i < len - 1; i++) {
                if (nums[i] > nums[i + 1]) {
                    return false;
                }
            }
        } else if (delta < 0) {
            for (int i = 0; i < len - 1; i++) {
                if (nums[i] < nums[i + 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};
