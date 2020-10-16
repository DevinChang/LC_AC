
void preOrder(TreeNode *root, int &count) {
    if(root == nullptr) return;
    count++;
    preOrder(root->left);
    preOrder(root->right);
}

int countNodes(TreeNode* root) {
    int ret = 0;
    preOrder(root, ret);
    return ret;
}


int countNodes(TreeNode *root){
    if(root == nullptr) return 0;
    auto l = root->left, r = root->right;
    int hl = 1, hr = 1;
    while(l) hl++, l = l->left;
    while(r) hr++, r = r->right;
    if(hl == hr) return (1 << hl) - 1;
    return countNodes(root->left) + countNodes(root->right) + 1;
}