

vector<int> inorderTraversal(TreeNode *root){
    stack<TreeNode*> st;
    vector<int> res;
    while(root || st.size()) {
        while(root) {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        res.push_back(root->val);
        root = root->right;
    }
    return res;
}