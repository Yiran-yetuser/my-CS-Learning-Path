class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int len = nums.size();
        if (nums[0] >= nums[1] || nums[len - 2] >= nums[len - 1]) {
            return false;
        }

        int peakCount = 0, valleyCount = 0;
        int peakPos, valleyPos;
        for (int i = 1; i < len - 1; i++) {
            if (nums[i - 1] == nums[i] || nums[i] == nums[i + 1]) {
                return false;
            }
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                peakCount++;
                peakPos = i;
            } else if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1]) {
                valleyCount++;
                valleyPos = i;
            }
        }
        // 更聪明的解法：用差值之积判断是否是极值点
        // if ((nums[i - 2] - nums[i - 1]) * (nums[i - 1] - nums[i]) < 0) {
        //         count++;
        //     }
        return peakCount == 1 && valleyCount == 1 && peakPos < valleyPos;
    }
};
