class Solution {
public:
    // ========== 并查集模板 ==========
    struct DSU {
        vector<int> parent; // 父节点数组
        vector<int> rank;   // 秩数组（树高）

        // 构造函数：初始化 n 个节点
        DSU(int n) {
            parent.resize(n + 1);  // 节点编号 1~n
            rank.resize(n + 1, 0); // 初始高度为 0
            for (int i = 0; i <= n; i++) {
                parent[i] = i; // 每个节点的父节点是自己
            }
        }

        // 查找根节点（带路径压缩）
        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]); // 路径压缩：直接连到根
            }
            return parent[x];
        }

        // 合并两个集合（按秩合并）
        bool unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);

            if (rootX != rootY) { // 不在同一集合，可以合并
                if (rank[rootX] < rank[rootY]) {
                    parent[rootX] = rootY; // 矮树挂高树
                } else if (rank[rootX] > rank[rootY]) {
                    parent[rootY] = rootX;
                } else {
                    parent[rootY] = rootX;
                    rank[rootX]++; // 高度相同，新根高度 +1
                }
                return true;
            }
            return false; // 已在同一集合，合并失败
        }
    };
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(), edges.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[3] == 0 && b[3] == 1) {
                     return false;
                 }
                 if (a[3] == 1 && b[3] == 0) {
                     return true;
                 }
                 return a[2] > b[2];
             });
        DSU dsu(n);
        int edgeCount = 0;
        int minWeigh = -1;
        int start0Index = 0;
        vector<vector<int>> tree;
        for (auto& edge : edges) {
            int start = edge[0];
            int end = edge[1];
            if (edge[3] == 1) {
                start0Index++;
            }
            if (dsu.unite(start, end)) {
                edgeCount++;
                tree.push_back(edge);
            } else {
                if (edge[3] == 1) {
                    return -1; // 必选项构成环，违反性质
                }
            }
            if (edgeCount == n - 1 && edge[3] == 0) {
                break; // 已有找到最大生成树，结束循环
            }
        }
        if (edgeCount < n - 1) {
            return -1; // 无法生成树，返回-1
        }
        minWeigh = start0Index == 0 ? tree[n - 2][2] * 2 + 1
                                    : tree[start0Index - 1][2];
        for (int i = n - 2; i >= 0; i--) {
            if (k == 0 || tree[i][3] == 1) {
                minWeigh = min(minWeigh, tree[i][2]);
                return minWeigh;
            }
            tree[i][2] *= 2;
            k--;
            minWeigh = min(tree[i][2], minWeigh);
        }
        return minWeigh;
    }
};
