class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size(); // 声明nums的大小
        for (int i = 0, j = 1; j < len; j++) {
            if (nums[i] == 0 && nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
            } // 如果i为0而j不为0，交换i的位置，并且将i向前移动一位
            if (nums[i] != 0) {
                i++;
            } // 如果i不为0，将i向前移动一位
        } // 每次循环都将j向前移动一位
    }
};
