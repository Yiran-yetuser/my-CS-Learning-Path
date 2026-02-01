class Solution {
public:
    int romanToInt(string s) {
        // 使用map容器存储字符和数值
        std::unordered_map<char, int> romans = {
            {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000},
        };
        int len = s.size();
        int number = romans[s[len - 1]];
        for (int index = len - 1; index > 0; index--) {
            // 如何判断？
            // 如果前一位小于索引位，那么必然是减法运算
            number += romans[s[index - 1]] < romans[s[index]]
                          ? (-romans[s[index - 1]])
                          : romans[s[index - 1]];
        }
        return number;
    }
};
