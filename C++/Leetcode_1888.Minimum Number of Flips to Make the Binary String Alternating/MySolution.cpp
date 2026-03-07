class Solution {
public:
    int minFlips(string s) {
        int len = s.size();
        int minimum = len;
        int currentCount = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == '0' + i % 2) {
                currentCount++;
            }
        }
        minimum = min(minimum, min(len - currentCount, currentCount));
        if (len % 2 == 1) {
            // 滑动窗口
            for (int left = 1; left < len; left++) {
                if (s[left - 1] == '0' + (left - 1) % 2) {
                    currentCount--;
                } else {
                    currentCount++;
                }
                minimum = min(minimum, min(len - currentCount, currentCount));
            }
        }
        return minimum;
    }
};
