class Solution {
public:
    // 相当暴力的解法，本质思想是快速幂 + 递归
    // 为了避免 int 型变量正负范围不同的问题直接用 long long 型代替
    // 时间复杂度 O( logn )，空间复杂度 O( logn )
    double fastPow(double x, long long n) {
        if (n == 0) {
            if (x == 0) {
                return 0.0;
            } else
                return 1.0;
        }
        if (x == 0)
            return 0.0;
        if (x == 1)
            return 1.0;
        if (x == -1) {
            return (n % 2 == 0) ? 1 : -1;
        }

        if (n < 0)
            return 1 / fastPow(x, -n);
        if (n % 2 == 0)
            return myPow(x * x, n / 2);
        else
            return x * myPow(x * x, n / 2);
    }
    double myPow(double x, int n) {

        /* 暴力解法，n太大就不行
        double result = 1;
        if (n > 0) {
            for (int i = 0; i < n; i++) {
                result *= x;
            }
            return result;
        } else {
            for (int i = 0; i > n; i--) {
                result /= x;
            }
        }
        return result;
        */
        long long N = n;
        return fastPow(x, N);
    }
};
/* 另一种解法，快速幂 + 迭代，精妙的地方在于二进制拆分
    时间复杂度 O( logn )，空间复杂度 O(1)（不需要额外栈空间）
double quickMul(double x, long long N) {
        double ans = 1.0;
        // 贡献的初始值为 x
        double x_contribute = x;
        // 在对 N 进行二进制拆分的同时计算答案
        while (N > 0) {
            if (N % 2 == 1) {
                // 如果 N 二进制表示的最低位为 1，那么需要计入贡献
                ans *= x_contribute;
            }
            // 将贡献不断地平方
            x_contribute *= x_contribute;
            // 舍弃 N 二进制表示的最低位，这样我们每次只要判断最低位即可
            N /= 2;
        }
        return ans;
    }

    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
    */

/* 个人觉得最优秀的解法
    简洁而且逻辑清晰

double myPow(double x, int n) {
    double res = 1.0;
    for(int i = n; i != 0; i /= 2){
        if(i % 2 != 0){
            res *= x;
        }
        x *= x;
    }
    return  n < 0 ? 1 / res : res;
}
*/
