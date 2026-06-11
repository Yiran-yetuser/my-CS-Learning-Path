class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> tree(n + 1); // 构建树
        for (auto& e : edges) {
            int x = e[0];
            int y = e[1];
            tree[x].push_back(y);
            tree[y].push_back(x);
        }
        auto dfs = [&](this auto&& dfs, int u, int f) -> int {
            int ans = -1;
            for (int v : tree[u]) {
                if (v == f) {
                    continue;
                }
                ans = max(ans, dfs(v, u));
            }
            return ans + 1;
        };
        int d = dfs(1, 0) - 1;
        long long ans = 1;
        while (d--) {
            ans <<= 1;
            ans %= 1000000007;
        }
        return ans;
    }
};
