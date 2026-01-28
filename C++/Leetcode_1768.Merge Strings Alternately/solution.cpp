class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        std::string merged;
        int i = 0, j = 0;
        int len1 = word1.size(), len2 = word2.size();

        // 交替合并，直到其中一个字符串用完
        while (i < len1 && j < len2) {
            merged.push_back(word1[i++]);
            merged.push_back(word2[j++]);
        }

        // 将剩余部分全部追加
        while (i < len1)
            merged.push_back(word1[i++]);
        while (j < len2)
            merged.push_back(word2[j++]);

        return merged;
    }
};
