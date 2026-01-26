class Solution {
public:
    int countOdds(int low, int high) {
        if ((high - low) % 2 == 0) {
            if (high % 2 == 0) {
                return (high - low) / 2;
            } else {
                return (high - low) / 2 + 1;
            }
        } else {
            return (high - low) / 2 + 1;
        }
        /* 更短的解法
        return (high + 1) / 2 - low / 2;
        */
    }
};
