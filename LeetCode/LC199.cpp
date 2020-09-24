


vector<int> rightSideView(TreeNode *root) {
    queue<TreeNode*> que;
    vector<int> ret;
    if(root == nullptr) return ret;
    que.push(root);
    while(que.size()) {
        int n = que.size();
        for(int i = 0; i < n; i++) {
            TreeNode *cur = que.front();
            que.pop();
            if(cur->left) que.push(cur->left);
            if(cur->right) que.push(cur->right);
            if(i == n-1) ret.push_back(cur->val);
        }
    }
    return ret;
}