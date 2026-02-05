class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int len = mat.size();
        int ans = 0;
        for (int i = 0; i < len; i++) {
            ans += mat[i][i] + ((i == len - i - 1) ? 0 : mat[i][len - i - 1]);
        }
        return ans;
    }
};
