class UnionFind {
private:
    std::vector<int> parent;
    std::vector<int> rank; // 或改为 size，取决于你想用按秩合并还是按大小合并
    int components;        // 连通分量计数

public:
    // 1. 构造函数：初始化 n 个独立节点
    UnionFind(int n) {
        // TODO:
        // - parent.resize(n) 并令 parent[i] = i
        // - rank 初始化为 0 (或 size 初始化为 1)
        // - components = n
        // 提示：可用 std::iota(parent.begin(), parent.end(), 0); 快速初始化
        components = n;
        rank.resize(n, 0); // 或 size.resize(n, 1);
        parent.resize(n);
        std::iota(parent.begin(), parent.end(), 0);
    }

    // 2. 查找根节点（必须包含路径压缩）
    int find(int x) {
        // TODO:
        // - 若 parent[x] == x，直接返回 x
        // - 否则递归/迭代找根，并将 parent[x] 指向根（路径压缩）
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // 3. 合并两个集合
    bool unite(int x, int y) {
        // TODO:
        // - 分别找 x, y 的根 rootX, rootY
        // - 若 rootX == rootY，返回 false（已连通）
        // - 否则按 rank/size 决定谁指向谁，更新 rank/size
        // - components--，返回 true
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return false;
        }
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootX] = rootY;
            rank[rootY]++;
        }

        components--;
        return true;
    }

    // 4. 查询连通性
    bool connected(int x, int y) {
        // TODO: 调用 find(x) == find(y)
        return find(x) == find(y);
    }

    int getComponentCount() const { return components; }
};
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        UnionFind dsu(n);
        for (auto& s : allowedSwaps) {
            int p = dsu.find(s[0]), q = dsu.find(s[1]);
            if (p != q) {
                dsu.unite(p, q);
            }
        }
        vector<int64_t> S(n), T(n);
        for (int i = 0; i < n; i++) {
            int64_t u32 = int64_t(dsu.find(i)) << 32;
            S[i] = u32 | source[i], T[i] = u32 | target[i];
        }
        sort(S.begin(), S.end());
        sort(T.begin(), T.end());
        int same = 0;
        for (int i = 0, j = 0; i < n && j < n;) {
            if (S[i] == T[j]) {
                ++same;
                i++;
                j++;
            } else {
                (S[i] < T[j] ? i : j)++;
            }
        }
        return n - same;
    }
};
