class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // time complexity O(n)
        // space complexity O(1)
        int len = digits.size();
        digits[len - 1]++;
        for (int i = len - 1; i > 0; i--) {
            if (digits[i] >= 10) {
                digits[i] -= 10;
                digits[i - 1]++;
            } // 进位
        }
        if (digits[0] >= 10) {
            digits.emplace(digits.begin(), 1);
            digits[1] = 0;
        }
        return digits;
    }
};
