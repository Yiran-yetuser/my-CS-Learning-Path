class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return -1;
        }

        array<int, 2> initArr;
        initArr.fill(-n); // 先将一个 array 填满 -n
        vector<array<int, 2>> last(n, initArr);

        int minimum = n;
        for (int i = 0; i < n; i++) {
            int x = nums[i] - 1;
            minimum = min(minimum, i - last[x][0]);
            last[x][0] = last[x][1];
            last[x][1] = i;
        }

        return minimum == n ? -1 : 2 * minimum;
    }
};
