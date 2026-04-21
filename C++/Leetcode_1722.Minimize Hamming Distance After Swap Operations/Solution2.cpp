class Solution {
public:
    vector<int> fa;
    int find(int u) {
        return fa[u] == u ? u : fa[u] = find(fa[u]);
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        fa.resize(n);
        for (int i = 0; i < n; i++) fa[i] = i;
        for (auto &w : allowedSwaps) {
            int p = find(w[0]), q = find(w[1]);
            if (p != q) fa[p] = q;
        }
        vector<int64_t> S(n), T(n);
        for (int i = 0; i < n; i++) {
            int64_t u32 = int64_t(find(i)) << 32;
            S[i] = u32 | source[i], T[i] = u32 | target[i];
        }
        sort(S.begin(), S.end());
        sort(T.begin(), T.end());
        int same = 0;
        for (int i = 0, j = 0; i < n && j < n; ) {
            if (S[i] == T[j]) {
                ++same; i++; j++;
            } else {
                (S[i] < T[j] ? i : j)++;
            }
        }
        return n - same;
    }
};

作者：七海Qiaqia7mi
链接：https://leetcode.cn/problems/minimize-hamming-distance-after-swap-operations/solutions/3955896/shuang-100-qiu-jiao-ji-pai-xu-shuang-zhi-k42c/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
