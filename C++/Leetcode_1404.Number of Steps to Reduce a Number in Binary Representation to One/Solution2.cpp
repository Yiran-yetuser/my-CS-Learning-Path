class Solution {
public:
    int numSteps(string s) {
        bool changed = false;
        int count = 0;
        int oneCount = 0;
        for (int i = s.size() - 1; i > 0; i--) {
            if (s[i] == '1') {
                if (!changed) {
                    count++;
                    changed = true;
                }
                oneCount++;
            } else {
                if (changed) {
                    count += oneCount + 1;
                    oneCount = 1;
                } else {
                    count++;
                }
            }
        }
        count += oneCount + (changed ? 1 : 0);
        return count;
    }
};
