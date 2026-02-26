class Solution {
public:
    int numSteps(string s) {
        int count = 0;
        while (s != "1") {
            if (s.back() == '0') {
                s.pop_back();
                count++;
            } else {
                int firstZero = s.size() - 1;
                while (firstZero >= 0 &&
                       s[firstZero] == '1') { // 注意条件先后顺序
                    s[firstZero] = '0';
                    firstZero--;
                }
                if (firstZero < 0) {
                    s.insert(s.begin(), '1');
                } else {
                    s[firstZero] = '1';
                }
                count++;
            }
        }
        return count;
    }
};
