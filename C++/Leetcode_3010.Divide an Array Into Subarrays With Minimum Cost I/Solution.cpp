class Solution {
public:
    int minimumCost(vector<int>& nums) {
        // 双指针遍历法, time complexity = O(n)
        // int min = nums[1], secondMin = nums[2];
        // if (min > secondMin) {
        //     swap(min, secondMin);
        // }
        // int len = nums.size();
        // if (len > 3) {
        //     for (int i = 3; i < len; i++) {
        //         if (nums[i] < min) {
        //             swap(min, secondMin);
        //             min = nums[i];
        //         } else if (nums[i] >= min && nums[i] < secondMin) {
        //             secondMin = nums[i];
        //         }
        //     }
        // }

        // 排序法, time complexity = O(nlogn)
        sort(nums.begin()+1,nums.end());
        int min = nums[1], secondMin = nums[2];
        return min + secondMin + nums[0];
    }
};
