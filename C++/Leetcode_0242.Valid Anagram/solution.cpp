class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> alpha(26,0) ;
        int lens = s.length(), lent = t.length();
        if(lens!=lent) {
            return false;
        }
        for(int i = 0; i < lens; i++) {
            alpha[s[i] - 'a']++;
        }
         for(int i = 0; i < lent; i++) {
            alpha[t[i] - 'a']--;
            // 提前终止条件
            if(alpha[t[i] - 'a']<0) {
                return false;
            }
        }      
        for(int i = 0;i<26;i++) {
            if(alpha[i]!=0) {
                return false;
            }
        }
        return true;
    }
};
