class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int right = 0, left = 0;
        for (auto& m : moves) {
            if (m == 'L') {
                left++;
                right--;
            } else if (m == 'R') {
                right++;
                left--;
            } else {
                left++;
                right++;
            }
        }
        return max(left, right);
    }
};
