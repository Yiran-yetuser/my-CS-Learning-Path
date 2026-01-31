class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        // 直接使用sort排序偷懒
        sort(arr.begin(), arr.end());
        for (int i = 1; i < arr.size() - 1; ++i) {
            if (arr[i] * 2 != arr[i - 1] + arr[i + 1]) {
                return false;
            }
        }
        return true;
    }
};
