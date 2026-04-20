class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int leftmax = 0, rightmax = 0;
        int n = colors.size();
        for (int i = 0; i < n; i++) {
            if (colors[i] != colors[n - 1]) {
                rightmax = n - 1 - i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (colors[i] != colors[0]) {
                leftmax = i;
                break;
            }
        }
        return max(leftmax, rightmax);
    }
};
