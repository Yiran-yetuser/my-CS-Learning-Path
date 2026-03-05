class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            int onePos = -1;
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    if (onePos >= 0) {
                        onePos = -1;
                        break;
                    }
                    onePos = j;
                }
            }
            if (onePos == -1) {
                continue;
            }
            ans++; // 先加一
            for (int k = 0; k < m; k++) {
                if (k == i) {
                    continue;
                }
                if (mat[k][onePos] == 0) {
                    continue;
                } else {
                    ans--; // 不符合条件，减去前面加的1
                    break; // 退出循环
                }
            }
        }
        return ans;
    }
};
