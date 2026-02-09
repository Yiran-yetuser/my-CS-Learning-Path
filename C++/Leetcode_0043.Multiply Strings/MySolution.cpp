class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        
        int len1 = num1.size();
        int len2 = num2.size();
        // 创建结果数组（最大长度 = len1 + len2）
        vector<int> res(len1 + len2, 0);
        
        // 从低位到高位遍历
        for (int i = len1 - 1; i >= 0; i--) {
            for (int j = len2 - 1; j >= 0; j--) {
                int digit1 = num1[i] - '0';
                int digit2 = num2[j] - '0';
                int product = digit1 * digit2;
                
                // 乘积影响两个位置：pos1 = i+j（高位）, pos2 = i+j+1（低位）
                int pos1 = i + j;
                int pos2 = i + j + 1;
                
                // 累加到对应位置
                int sum = product + res[pos2];
                res[pos2] = sum % 10;      // 保留个位
                res[pos1] += sum / 10;      // 进位加到高位
            }
        }
        
        // 转换为字符串（跳过前导零）
        string ans;
        int start = 0;
        while (start < res.size() && res[start] == 0) {
            start++; // 跳过前导零
        }
        for (int i = start; i < res.size(); i++) {
            ans.push_back(res[i] + '0');
        }
        return ans;
    }
};
