class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        // 线性查找法
        // for (int i =0; i < letters.size(); i++) {
        //     if (letters[i] > target ) {
        //         return letters[i];
        //     }
        // }
        // return letters[0];

        // 二分查找法
        int len = letters.size(); // 数组长度
        int left = 0;
        int right = len - 1;
        int middle = -1;
        while (left != right) {
            middle = left + (right - left) / 2;
            if (letters[middle] <= target) {
                left = middle + 1;
            } else {
                right = middle;
            }         
        }
        return letters[left] >target ? letters[left]:letters[0];
    }
};
