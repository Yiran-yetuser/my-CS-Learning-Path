class Solution {
public:
    int mirrorDistance(int n) {
        int ans = 0;
        int temp = n;
        while (temp > 0) {
            ans = ans * 10 + temp % 10;
            temp /= 10;
        }
        return abs(ans - n);
    }
};
