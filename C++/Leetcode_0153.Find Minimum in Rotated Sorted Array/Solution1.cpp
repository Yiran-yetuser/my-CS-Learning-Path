class Solution {
public:
    int findMin(vector<int>& nums) {
        // 找规律：若最后一个数字不是目标，则比最后一个数小的第一个数就是最小值
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        int left = 0;
        int right = n - 1;
        int last = nums[n - 1];
        if (nums[0] < last) {
            return nums[0];
        }

        while (left < right - 1) {
            int middle = (left + right) / 2;
            if (nums[middle] < last) {
                right = middle;
            } else {
                left = middle;
            }
        }
        return min(nums[left], nums[right]);
    }
};
