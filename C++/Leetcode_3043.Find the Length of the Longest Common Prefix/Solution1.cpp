class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> s;
        for (int i = 0; i < arr1.size(); i++) {
            int x = arr1[i];
            while (x > 0) {
                s.insert(x);
                x /= 10;
            }
        }
        int maximum = 0;
        for (int i = 0; i < arr2.size(); i++) {
            int y = arr2[i];
            while (y > 0 && s.contains(y) == false) {
                y /= 10;
            }
            if (y > maximum) {
                maximum = y;
            }
        }
        int digit = 0;
        while (maximum > 0) {
            maximum /= 10;
            digit++;
        }
        return digit;
    }
};
