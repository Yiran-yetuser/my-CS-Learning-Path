class Solution {
public:
    int minOperations(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0' + i % 2) {
                count++;
            }
        }
        return (count>s.size()-count)?s.size()-count:count;
    }
};
