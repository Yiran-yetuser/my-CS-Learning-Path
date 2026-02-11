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
    // // 递归做法
    // void inorder(TreeNode* root, vector<int>& res) {
    //     if(root == nullptr) {
    //         return;
    //     }
    //     inorder(root->left,res);
    //     res.push_back(root->val);
    //     inorder(root->right,res);
    // }

    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     inorder(root,res);
    //     return res;
    // }

    // 迭代做法
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while (cur != nullptr || !stk.empty()) {
            while (cur != nullptr) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
        return res;
    }
};
