class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int count = 0, index1 = startIndex, index2 = startIndex;
        while (words[index1] != target && words[index2] != target) {
            index1 = (index1 + 1) % n;
            index2 = (index2 - 1 + n) % n;
            count++;
            if (count >= n - 1) {
                return -1;
            }
        }
        return count;
    }
};
