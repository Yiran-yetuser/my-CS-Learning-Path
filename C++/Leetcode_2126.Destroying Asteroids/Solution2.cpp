class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int max_width = bit_width(1u * ranges::max(asteroids));
        vector<int> mn(max_width, INT_MAX);
        vector<long long> sum(max_width);

        for (int x : asteroids) {
            int i = bit_width(1u * x) - 1;
            mn[i] = min(mn[i], x);
            sum[i] += x;
        }

        long long m = mass;
        for (int i = 0; i < max_width; i++) {
            if (mn[i] == INT_MAX) {
                continue;
            }
            if (m < mn[i]) { // 无法摧毁这组的任意小行星
                return false;
            }
            m += sum[i]; // 获得这组小行星的质量
        }
        return true;
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/destroying-asteroids/solutions/1/tan-xin-cong-zui-xiao-de-kai-shi-peng-zh-h7d4/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
