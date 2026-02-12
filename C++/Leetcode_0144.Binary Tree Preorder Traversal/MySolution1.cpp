class Solution {
public:
    // 递归法
    void preorder(TreeNode* root, vector<int>& res) {
        if(!root) {
            return;
        }
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root,res);
        return res;
    }

    // // 迭代法
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> res;
        
    //     if (root == nullptr) {
    //         return res;
    //     }
    //     stack<TreeNode*> stk;
    //     TreeNode* cur = root;
    //     while (cur != nullptr || !stk.empty()) {
    //         while (cur != nullptr) {
    //             res.push_back(cur->val);
    //             stk.push(cur);
    //             cur = cur->left;
    //         }
    //         cur = stk.top();
    //         stk.pop();
    //         cur = cur->right;
    //     }
    //     return res;
    // }
};
