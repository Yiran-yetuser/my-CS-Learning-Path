class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int grid[3][3] = {0};
        int turn = 1;
        for (int i = 0; i < moves.size(); i++) {
            grid[moves[i][0]][moves[i][1]] = turn;
            turn = -turn;
        } // 给方格填数值

        int sum = 0;
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                sum += grid[row][col];
            }
            if (abs(sum) == 3) {
                return sum > 0 ? "A" : "B";
            }
            sum = 0;
        } // 行判断

        for (int col = 0; col < 3; col++) {
            for (int row = 0; row < 3; row++) {
                sum += grid[row][col];
            }
            if (abs(sum) == 3) {
                return sum > 0 ? "A" : "B";
            }
            sum = 0;
        } // 列判断

        for (int j = 0; j < 3; j++) {
            sum += grid[j][j];
        }
        if (abs(sum) == 3) {
            return sum > 0 ? "A" : "B";
        } 
        sum = 0;
        for(int j = 0;j<3;j++) {
            sum+=grid[j][2-j];
        }
        if (abs(sum) == 3) {
            return sum > 0 ? "A" : "B";
        } // 对角线判断

        return moves.size() == 9 ? "Draw" : "Pending";
    }
};
