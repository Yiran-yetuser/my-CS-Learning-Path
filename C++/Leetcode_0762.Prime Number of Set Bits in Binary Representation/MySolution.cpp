class Solution {
public:
    bool isPrimeOfSetBits(int n) {
        int count = 0;
        while (n > 0) {
            if ((n & 1) == 1) {
                count++;
            }
            n >>= 1;
        }
        if (count < 2) {
            return false;
        }
        for (int i = 2; i * i <= count; i++) {
            if (count % i == 0) {
                return false;
            }
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for (int i = left; i <= right; i++) {
            if (isPrimeOfSetBits(i)) {
                count++;
            }
        }
        return count;
    }
};
