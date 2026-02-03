class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        # 3阶数独矩阵
        SUDOKU=[[6,1,8],[7,5,3],[2,9,4]]
        # 如果其中3数和为15就赢
        if 15 in [sum(k) for k in combinations([SUDOKU[i][j] for i,j in moves[::2]], 3)]:return "A"
        if 15 in [sum(k) for k in combinations([SUDOKU[i][j] for i,j in moves[1::2]], 3)]:return "B"
        return "Draw" if len(moves)==9 else "Pending"

作者：INN
链接：https://leetcode.cn/problems/find-winner-on-a-tic-tac-toe-game/solutions/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
