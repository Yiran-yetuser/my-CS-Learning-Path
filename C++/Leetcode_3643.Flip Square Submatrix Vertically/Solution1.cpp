class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int p = x, q = x + k - 1; p < q; p++, q--) {
            for (int i = y; i < y + k; i++) {
                swap(grid[p][i], grid[q][i]);
            }
        }
        return grid;
    }
};
