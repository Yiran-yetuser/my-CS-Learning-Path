class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>()); // 降序排列
        int len  = nums.size();
        for(int i = 0;i<len-2;i++) {
            if(nums[i]<nums[i+1]+nums[i+2]) {
                return nums[i]+nums[i+1]+nums[i+2];
            }
        }
        return 0;
    }
};
