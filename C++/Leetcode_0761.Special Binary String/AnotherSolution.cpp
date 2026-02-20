class Solution {
public:
    // 用于记录节点及其排名的结构体
    struct Node {
        int idx, rank;
        bool operator<(const Node& other) const {
            return rank < other.rank;
        }
        bool operator>(const Node& other) const {
            return rank > other.rank;
        }
        bool operator==(const Node& other) const {
            return rank == other.rank;
        }
    };

    // 用于处理同高度节点排序的结构体
    struct Item {
        int idx;
        const vector<Node>* children;
        bool operator<(const Item& other) const {
            return *children < *other.children;
        }
    };

    // 将树转化为字符串
    void dfs(const vector<vector<Node>>& children, string& ans, int u) {
        ans += '1';
        for (auto [v, _] : children[u])
            dfs(children, ans, v);
        ans += '0';
    }

    string makeLargestSpecial(string s) {
        const int n = s.size(), m = n / 2 + 1;
        // 记录每个节点的父节点与子树高度
        vector<int> parent(m, -1), height(m);
        // 记录每个节点的所有子结点
        vector<vector<Node>> children(m);
        // 按子树高度对节点分类
        vector<vector<int>> levels(m);
        // 栈，栈中记录节点编号
        stack<int> stk;
        stk.push(0);
        // 节点编号
        int idx = 1;
        for (char c : s) {
            switch (c) {
            case '1':
                // 遇到左括号，新增一个节点
                // 新增节点的父节点设为栈顶
                parent[idx] = stk.top();
                // 新节点入栈
                stk.push(idx++);
                break;
            case '0':
                {
                    // 遇到右括号，弹出栈顶节点
                    const int t = stk.top();
                    stk.pop();
                    // 弹出节点的所有子结点已经处理完毕
                    // 因此弹出节点的子树高度已经确定
                    // 将弹出节点加入对应的分类中
                    levels[height[t]].push_back(t);
                    // 用弹出节点的子树高度更新父节点的子树高度
                    if (height[stk.top()] < height[t] + 1)
                        height[stk.top()] = height[t] + 1;
                    break;
                }
            }
        }
        // 将第 0 层的节点加入其对应父节点的子结点集合中
        // 加入的同时附带上节点的排名
        // 由于第 0 层的节点全部相等
        // 因此排名全部为 0
        for (int e : levels[0])
            children[parent[e]].push_back({e, 0});
        // 任取一个第 0 层的节点作为当前排名最大的节点记录下来
        const vector<Node>* pre = &children[levels[0][0]];
        // 按层遍历，rank 代表当前的最大排名
        for (int rank = 0, i = 1;i < m;++i) {
            // 收集所有同高度的节点
            vector<Item> order;
            for (int e : levels[i]) {
                // 对每个结点的子结点排序
                sort(children[e].begin(), children[e].end(), greater<Node>{});
                order.push_back({e, &children[e]});
            }
            sort(order.begin(), order.end());
            for (auto [e, cur] : order) {
                // 当前节点与之前排名最大的节点不同
                // 当前节点变为新的排名最大的节点
                // 且最大排名增加 1
                if (*pre != *cur) {
                    pre = cur;
                    ++rank;
                }
                // 当前节点的排名已经确定，将其加入其父节点的子结点集合中
                children[parent[e]].push_back({e, rank});
            }
        }
        string ans;
        // 编号为 0 的节点是虚拟节点，用于将所有节点统一到一颗树下
        sort(children[0].begin(), children[0].end(), greater<Node>{});
        // 使用深度优先搜索遍历节点，将树转化为字符串
        for (auto [e, _] : children[0])
            dfs(children, ans, e);
        return ans;
    }
};

作者：白
链接：https://leetcode.cn/problems/special-binary-string/solutions/1730884/onlogn-by-vclip-eyy8/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
