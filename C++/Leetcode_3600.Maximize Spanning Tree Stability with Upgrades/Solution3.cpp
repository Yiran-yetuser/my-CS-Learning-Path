class UnionFind {
    vector<int> fa; // 代表元

public:
    int cc; // 连通块个数

    UnionFind(int n) : fa(n), cc(n) {
        // 一开始有 n 个集合 {0}, {1}, ..., {n-1}
        // 集合 i 的代表元是自己
        ranges::iota(fa, 0);
    }

    // 返回 x 所在集合的代表元
    // 同时做路径压缩，也就是把 x 所在集合中的所有元素的 fa 都改成代表元
    int find(int x) {
        // 如果 fa[x] == x，则表示 x 是代表元
        if (fa[x] != x) {
            fa[x] = find(fa[x]); // fa 改成代表元
        }
        return fa[x];
    }

    // 把 from 所在集合合并到 to 所在集合中
    // 返回是否合并成功
    bool merge(int from, int to) {
        int x = find(from), y = find(to);
        if (x == y) { // from 和 to 在同一个集合，不做合并
            return false;
        }
        fa[x] = y; // 合并集合。修改后就可以认为 from 和 to 在同一个集合了
        cc--; // 成功合并，连通块个数减一
        return true;
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        UnionFind uf(n);
        UnionFind all_uf(n);
        int min_s1 = INT_MAX;
        for (auto& e : edges) {
            int x = e[0], y = e[1], s = e[2], must = e[3];
            if (must) {
                if (!uf.merge(x, y)) { // 必选边成环
                    return -1;
                }
                min_s1 = min(min_s1, s);
            }
            all_uf.merge(x, y);
        }

        if (all_uf.cc > 1) { // 图不连通
            return -1;
        }

        int left = uf.cc - 1;
        if (left == 0) { // 只需选必选边
            return min_s1;
        }

        // Kruskal 求最大生成树
        ranges::sort(edges, {}, [](auto& e) { return -e[2]; });
        int ans = min_s1;
        for (auto& e : edges) {
            int x = e[0], y = e[1], s = e[2], must = e[3];
            if (!must && uf.merge(x, y)) {
                ans = min(ans, left > k ? s : s * 2);
                left--;
                if (left == 0) { // 已经得到生成树了
                    break;
                }
            }
        }
        return ans;
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/maximize-spanning-tree-stability-with-upgrades/solutions/3711009/liang-chong-fang-fa-er-fen-da-an-kruskal-6p7a/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
