//这个是详细注释的版本
// Trie 树节点
// 因为题目中比较的是整数的十进制前缀，所以每个节点最多有 10 个子节点，分别对应数字 0~9
class node {
public:
    // next[i] 表示当前节点往数字 i 走到的下一个节点
    // 例如 next[3] 不为空，说明当前前缀后面可以接数字 3
    node* next[10];

    // 构造函数：新建节点时，把所有子节点初始化为空
    node() {
        for (int i = 0; i < 10; i++) {
            next[i] = nullptr;
        }
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        // 创建 Trie 的根节点
        // 根节点本身不存储任何数字，只作为所有数字前缀的起点
        node* root = new node();

        // 第一步：把 arr1 中所有数字插入 Trie
        for (auto ch : arr1) {
            // 将整数转成字符串，方便按位处理
            // 例如 12345 转成 "12345"
            string s = to_string(ch);

            // r 用来遍历当前 Trie 路径，初始指向根节点
            node* r = root;

            // 逐位插入当前数字
            for (auto ch2 : s) {
                // 当前数字字符对应的下标
                // 例如 '7' - '0' = 7
                int idx = ch2 - '0';

                // 如果当前路径已经存在，直接往下走
                if (r->next[idx] != nullptr) {
                    r = r->next[idx];
                } 
                // 如果当前路径不存在，说明这个前缀还没有出现过，需要新建节点
                else {
                    r->next[idx] = new node();
                    r = r->next[idx];
                }
            }
        }

        // ret 记录答案，也就是最长公共前缀长度
        int ret = 0;

        // 第二步：用 arr2 中每个数字去 Trie 中匹配最长前缀
        for (auto ch : arr2) {
            // 同样先把整数转成字符串，方便逐位比较
            string s = to_string(ch);

            // 从 Trie 根节点开始匹配
            node* r = root;

            // get 表示当前这个 arr2 数字能匹配到的前缀长度
            int get = 0;

            // 逐位在 Trie 中查找
            for (auto ch2 : s) {
                int idx = ch2 - '0';

                // 如果 Trie 中存在这条路径，说明这一位可以匹配
                if (r->next[idx] != nullptr) {
                    r = r->next[idx];
                    get++;
                } 
                // 如果不存在，说明公共前缀到这里结束
                else {
                    break;
                }
            }

            // 更新最大公共前缀长度
            ret = max(ret, get);
        }

        // 返回 arr1 和 arr2 任意两个数之间的最长公共前缀长度
        return ret;
    }
};

// 作者：Flerken
// 链接：https://leetcode.cn/problems/find-the-length-of-the-longest-common-prefix/solutions/3971915/zi-dian-shu-bu-yao-tai-jian-dan-by-flerk-l3sz/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
