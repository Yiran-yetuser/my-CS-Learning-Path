class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        using i64 = long long;
        vector<i64> pairs(n);
        for (int i = 0; i < n; i++) {
            pairs[i] = i64(arr[i]) << 32 | i;
        }
        sort(pairs.begin(), pairs.end());

        vector<int> dis(n, 0x3f3f3f3f), valVisited(n, 0);
        queue<int> Q;
        Q.push(0); dis[0] = 0;

        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            if (u == n - 1) return dis[u];

            auto put = [&](int v) {
                if (dis[v] > dis[u] + 1) {
                    dis[v] = dis[u] + 1;
                    Q.push(v);
                }
            };

            if (u > 0) put(u - 1);
            if (u < n - 1) put(u + 1);

            if (!valVisited[u]) {
                // value path can only be walked once
                i64 lb = i64(arr[u]) << 32, rb = i64(arr[u] + 1) << 32; // [lb, rb)
                auto ib = lower_bound(pairs.begin(), pairs.end(), lb);
                auto ie = lower_bound(pairs.begin(), pairs.end(), rb);
                for (auto it = ib; it != ie; it++) {
                    int v = (*it) & 0xffffffff;
                    put(v);
                    valVisited[v] = 1;
                }
            }
        }

        return dis[n - 1];
    }
};

// 作者：七海Qiaqia7mi
// 链接：https://leetcode.cn/problems/jump-game-iv/solutions/3970092/shuang-100-pai-xu-bfsyou-hua-by-gcc314-c0fa/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
