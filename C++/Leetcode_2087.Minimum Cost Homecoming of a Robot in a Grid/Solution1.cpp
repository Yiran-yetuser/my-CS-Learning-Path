class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos,
                vector<int>& rowCosts, vector<int>& colCosts) {
        int ans = 0;
        // 四个方向移动，但是实际上只需要两个方向
        // 虽然说有多种方式，但是实际上按最短路径走法结果一模一样
        int deltaX = homePos[0] - startPos[0];
        int deltaY = homePos[1] - startPos[1];
        for (int i = 1; i <= abs(deltaX); i++) {
            ans += deltaX > 0 ? rowCosts[startPos[0] + i]
                              : rowCosts[startPos[0] - i];
        }
        for (int i = 1; i <= abs(deltaY); i++) {
            ans += deltaY > 0 ? colCosts[startPos[1] + i]
                              : colCosts[startPos[1] - i];
        }
        return ans;
    }
};
