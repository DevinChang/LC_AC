int n = 0;
int ret = 0;
void inorder(TreeNode *root, int k){
    if(root == nullptr) return;
    inorder(root->left, k);
    if(++n == k){
         ret = root->val;
         return;
    }
    inorder(root->right, k);
}

int kthSmallest(TreeNode* root, int k) {
    inorder(root, k);
    return ret;
}