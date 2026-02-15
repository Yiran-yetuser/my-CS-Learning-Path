class Solution {
public:
    int climbStairs(int n) {

        // 动态规划
        int x = 0, y = 1, z = 1;
        for (int i = 0; i < n - 1; i++) {
            x = y;
            y = z;
            z = x + y;
        }
        return z;

        // // 数学上正确的解法，但是超时了
        // if(n<=0) {
        //     return 0;
        // }
        // if(n==1 ){
        //     return 1;
        // }
        // if(n == 2) {
        //     return 2;
        // }
        // return climbStairs(n-1)+climbStairs(n-2);
    }
};
