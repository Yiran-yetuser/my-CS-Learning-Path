class Solution {
    static constexpr int MOD = 1'000'000'007;

    long long pow(long long x, int n) {
        long long res = 1;
        for (; n; n /= 2) {
            if (n % 2) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
        }
        return res;
    }

public:
    int concatenatedBinary(int n) {
        long long ans = 0;
        for (int w = 1; 1 << (w - 1) <= n; w++) {
            int l = 1 << (w - 1);
            int r = min((1 << w) - 1, n);
            int m = r - l + 1;
            int q = 1 << w;
            long long pow_q = pow(q, m);
            long long inv_q1 = pow(q - 1, MOD - 2);
            long long s = r * (pow_q - 1) % MOD * inv_q1 - (q - m * pow_q + (m - 1) * pow_q % MOD * q) % MOD * inv_q1 % MOD * inv_q1;
            ans = (ans * pow_q + s) % MOD;
        }
        return (ans + MOD) % MOD; // 保证结果非负
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/concatenation-of-consecutive-binary-numbers/solutions/511016/golang-jian-ji-xie-fa-by-endlesscheng-2cg5/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
