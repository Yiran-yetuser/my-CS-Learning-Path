class Solution {
public:
    int binaryGap(int n) {
        int maxDistance = 0;
        int count = 0;
        while ((n & 1) == 0) {
            n >>= 1;
        } // 去除尾零
        while (n > 0) {
            if ((n & 1) == 1) {
                maxDistance = maxDistance > count ? maxDistance : count;
                count = 1;
            } else {
                count++;
            }
            n >>= 1;
        }
        return maxDistance;
    }
};
