class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size();
        int endIndex,startIndex;
        for(int i = len -1;i>=0;i--) {
            if(isalpha(s[i])) {
                endIndex = i;
                break;
            }
        }
        for(int i = endIndex ;i>=0;i--) {
            if(!isalpha(s[i])) {
                startIndex = i+1;
                break;
            }
            if(i==0) {
                startIndex = i;
            }
        }
        return endIndex - startIndex + 1;
    }
};
