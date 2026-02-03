class Solution {
public:
    bool judgeCircle(string moves) {
        if (moves.length() % 2 != 0) {
            return false;
        }
        int x = 0, y = 0;
        for (auto &move : moves) {
            switch (move) {
            case 'U':
                y--;
                break;
            case 'D':
                y++;
                break;
            case 'L':
                x--;
                break;
            case 'R':
                x++;
                break;
            }
        }
        return x == 0 && y == 0;
    }
};
