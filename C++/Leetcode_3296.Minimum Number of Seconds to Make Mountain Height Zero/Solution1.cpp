class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        // check函数，用于判断mid是否够完成移山
        auto check = [&](long long mid) {
            int height = mountainHeight;
            for (auto& t : workerTimes) {
                height -= ((int)sqrt(mid / t * 8 + 1) - 1) / 2;
                if (height <= 0) {
                    return true;
                }
            }
            return false;
        };
        long long left = 0;
        int minTime = ranges::min(workerTimes);
        long long right = (long long)mountainHeight * (mountainHeight + 1) / 2 * minTime;

        while (left + 1 < right) {
            long long mid = (left + right) / 2;
            (check(mid) ? right : left) = mid;
        }
        return right;
    }
};
