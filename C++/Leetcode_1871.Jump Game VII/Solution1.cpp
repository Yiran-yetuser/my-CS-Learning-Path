class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if (s.back() == '1')
            return false; // 终点是 '1' 绝对不可达
        int n = s.size();

        vector<int8_t> can_reaches(n);
        can_reaches[0] = true;

        int j = 1;
        for (int i = 0; i < n && j < n; i++) {
            if (s[i] == '0' && can_reaches[i]) {
                // 注意 j 只会增大，不会减小，所以总体时间复杂度是 O(n)
                for (j = max(j, i + minJump); j <= min(i + maxJump, n - 1);
                     j++) {
                    can_reaches[j] = true; // 可以跳到 j
                }
            }
        }

        return s[n - 1] == '0' && can_reaches[n - 1];
    }
};
