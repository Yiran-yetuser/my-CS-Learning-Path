
class Solution {
public:
    string getHappyString(int n, int k) {
        int sum = 1 << (n - 1);  // 2^(n-1)
        
        // 检查范围
        if (k > 3 * sum) return "";
        string res = "";
        
        // 确定第一个字符
        if (k <= sum) res += 'a';
        else if (k <= 2 * sum) {
            res += 'b';
            k -= sum;
        } else {
            res += 'c';
            k -= 2 * sum;
        }
        
        // 迭代确定剩余字符
        for (int i = n - 1; i > 0; i--) {
            int max = 1 << (i - 1);
            char lastChar = res.back();
            
            if (lastChar == 'a') {
                res += (k <= max ? 'b' : 'c');
                if (k > max) k -= max;
            } else if (lastChar == 'b') {
                res += (k <= max ? 'a' : 'c');
                if (k > max) k -= max;
            } else {
                res += (k <= max ? 'a' : 'b');
                if (k > max) k -= max;
            }
        }
        
        return res;
    }
};
