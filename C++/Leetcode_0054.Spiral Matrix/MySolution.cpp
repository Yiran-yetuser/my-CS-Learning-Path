class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int baseRow = 0, baseColumn = 0;
        int maxRow = matrix.size() - 1;
        int maxColumn = matrix[0].size() - 1;
        vector<int> ans;
        while (baseRow <= maxRow && baseColumn <= maxColumn) {
            for (int i = baseColumn; i <= maxColumn; i++) {
                ans.push_back(matrix[baseRow][i]);
            }
            for (int i = baseRow + 1; i <= maxRow; i++) {
                ans.push_back(matrix[i][maxColumn]);
            }
            for (int i = maxColumn - 1; i >= baseColumn && maxRow != baseRow;
                 i--) {
                ans.push_back(matrix[maxRow][i]);
            }
            for (int i = maxRow - 1;
                 i >= baseRow + 1 && maxColumn != baseColumn; i--) {
                ans.push_back(matrix[i][baseColumn]);
            }
            baseColumn++;
            baseRow++;
            maxColumn--;
            maxRow--;
        }
        return ans;
    }
};
