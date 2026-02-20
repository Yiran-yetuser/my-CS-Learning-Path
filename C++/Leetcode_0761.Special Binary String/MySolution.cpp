class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> substring;
        int len = s.size();
        int count = 0, start = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == '1') {
                count++;
            } else {
                count--;
                if (count == 0) {
                    substring.push_back(
                        "1" +
                        makeLargestSpecial(s.substr(start + 1, i - start - 1)) +
                        "0"); // 递归部分
                    start = i + 1;
                }
            }
        }
        sort(substring.begin(), substring.end(), greater<string>());
        string res = accumulate(substring.begin(), substring.end(), ""s);
        return res;
    }
};
