/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    uint32_t dfs(TreeNode* root, uint32_t n) {
        if (root == nullptr) {
            return 0;
        }
        n = (n << 1) | root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return n;
        }
        return dfs(root->left, n) + dfs(root->right, n);
    }
    int sumRootToLeaf(TreeNode* root) {
        uint32_t n = 0;
        return dfs(root, n);
    }
};
