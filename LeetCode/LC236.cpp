TreeNode *res;

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == nullptr) return root;
    dfs(root, p, q);
    return res;
}


int dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
    if(root == nullptr) return 0;
    int state = dfs(root->left, p, q);
    if(root == p) state |= 1;
    else if (root == q) state |= 2;
    state |= dfs(root->right, p, q);
    if(state == 3 && res == nullptr) res = root;
    return state; 
}

