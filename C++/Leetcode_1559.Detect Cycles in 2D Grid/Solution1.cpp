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
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        UnionFind u(m * n + 1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j + 1 < n && grid[i][j] == grid[i][j + 1]) {
                    if (u.unite(i * n + j, i * n + j + 1) == false)
                        return true;
                }

                if (i + 1 < m && grid[i][j] == grid[i + 1][j]) {
                    if (u.unite(i * n + j, i * n + n + j) == false)
                        return true;
                }
            }
        }
        return false;
    }
};
