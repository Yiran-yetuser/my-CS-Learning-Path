class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if (mat == target) {
            return true;
        }
        int n = mat.size();
        auto rotate = [&]() -> void{
            for(int i = 0; i < n / 2; i++){
                for(int j = i; j < n - i - 1; j++){
                    int tmp = mat[i][j];
                    mat[i][j] = mat[n - j - 1][i];
                    mat[n - j - 1][i] = mat[n - i - 1][n - j - 1];
                    mat[n - i - 1][n - j - 1] = mat[j][n - i - 1];
                    mat[j][n - i - 1] = tmp;
                }
            }
        };
        int count = 3;
        while(count>0) {
            rotate();
            if(mat == target) {
                return true;
            }
            count--;
        }
        return false;
    }
};
