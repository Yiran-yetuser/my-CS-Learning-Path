#include <stdlib.h>

int maximumJumps(int* nums, int numsSize, int target) {
    int dp[numsSize];
    
    // 1. 用 -1 表示“不可达”，dp[0] = 0 表示起点不需要跳跃
    // 动态规划消除歧义！！！
    for (int i = 0; i < numsSize; i++) dp[i] = -1;
    dp[0] = 0;

    for (int i = 1; i < numsSize; i++) {
        int max_jumps = -1;
        for (int j = 0; j < i; j++) {
            // 2. 合并条件：满足跳跃距离 且 前一状态可达
            if (abs(nums[i] - nums[j]) <= target && dp[j] != -1) {
                if (dp[j] + 1 > max_jumps) {
                    max_jumps = dp[j] + 1;
                }
            }
        }
        dp[i] = max_jumps;
    }

    // 3. 直接返回末尾状态，无需额外判断
    return dp[numsSize - 1];
}
