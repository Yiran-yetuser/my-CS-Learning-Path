class Solution {
public:
    static bool cmp(int a, int b) {
        int countA = __builtin_popcount(a);
        int countB = __builtin_popcount(b);
        if (countA != countB) {
            return countA < countB;  // 按1的个数升序
        }
        return a < b;  // 1的个数相同，按数值升序
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};
