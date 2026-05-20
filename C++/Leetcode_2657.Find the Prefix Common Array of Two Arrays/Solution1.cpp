class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> res(n, 0);
        vector<int> cnt(n + 1, 0); // 记录每个数字的出现次数
        for (int i = 0; i < n; i++) {
            res[i] += i > 0 ? res[i - 1] : 0;
            cnt[A[i]]++;
            cnt[B[i]]++;
            if (cnt[A[i]] == 2 && A[i] != B[i]) {
                res[i]++;
            }
            if (cnt[B[i]] == 2) {
                res[i]++;
            }
        }
        return res;
    }
};
