class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int m = n ^ (n >> 1);
        return (m & (m + 1)) == 0;
        // int last = 1&n;
        // n>>=1;
        // while(n>0) {
        //     if((1&n) == last) {
        //         return false;
        //     }
        //     last = 1&n;
        //     n>>=1;
        // }
        // return true;
    }
};
