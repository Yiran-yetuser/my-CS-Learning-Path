 // Morris法 前序遍历
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        TreeNode* cur = nullptr;
        while (root != nullptr) {
            
            cur = root->left;
            if (cur == nullptr) {
                res.push_back(root->val);
                root = root->right;
            } else {
                while (cur->right != nullptr && cur->right != root) {
                    cur = cur->right;
                }
                if (cur->right == nullptr) {
                    res.push_back(root->val);
                    cur->right = root;
                    root = root->left;
                } else {
                    root = root->right;
                    cur->right = nullptr;
                }
            }
        }
        return res;
    }
