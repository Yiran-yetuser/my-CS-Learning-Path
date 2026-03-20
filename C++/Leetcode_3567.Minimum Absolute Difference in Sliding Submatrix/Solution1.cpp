class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> res(m - k + 1, vector<int>(n - k + 1));
        vector<int> vals(k * k);
        for (int i = 0; i < m - k + 1; i++) {
            for (int j = 0; j < n - k + 1; j++) {
                int index = 0;
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        vals[index++] = grid[x][y];
                    }
                }
                sort(vals.begin(), vals.end(), greater<int>());
                if (vals[0] == vals[k * k-1]) {
                    res[i][j] = 0;
                } else {
                    int minDiff = k > 1 ? 1000000 : 0;
                    for (int t = 0; t < k * k - 1; t++) {
                        if (vals[t] != vals[t + 1]) {
                            minDiff = min(minDiff, vals[t] - vals[t + 1]);
                        }
                    }
                    res[i][j] = minDiff;
                }
            }
        }

        return res;
    }
};
