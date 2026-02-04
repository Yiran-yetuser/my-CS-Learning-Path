class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0;
        int dir = 0;
        for (auto& instr : instructions) {
            switch (instr) {
            case 'L':
                dir = (dir + 3) % 4;
                break;
            case 'R':
                dir = (dir + 1) % 4;
                break;
            case 'G':
                switch (dir) {
                case 0:
                    y++;
                    break;
                case 1:
                    x++;
                    break;
                case 2:
                    y--;
                    break;
                case 3:
                    x--;
                    break;
                }
                break;
            }
        }
        return dir != 0 || (x == 0 && y == 0);
    }
};
