class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        auto check = [&](long long m) {
            int left_h = mountainHeight;
            for (int t : workerTimes) {
                left_h -= ((int) sqrt(m / t * 8 + 1) - 1) / 2;
                if (left_h <= 0) {
                    return true;
                }
            }
            return false;
        };

        int max_t = ranges::max(workerTimes);
        int h = (mountainHeight - 1) / workerTimes.size() + 1;
        long long left = 0, right = (long long) max_t * h * (h + 1) / 2;
        while (left + 1 < right) {
            long long mid = (left + right) / 2;
            (check(mid) ? right : left) = mid;
        }
        return right;
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/minimum-number-of-seconds-to-make-mountain-height-zero/solutions/2925848/er-fen-da-an-pythonjavacgo-by-endlessche-myg4/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
