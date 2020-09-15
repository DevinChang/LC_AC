class BSTIterator {
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        while(root){
            st.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        int res = 0;
        auto root = st.top();
        st.pop();
        res = root->val;
        root = root->right;
        while(root){
            st.push(root);
            root = root->left;
        }
        return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return st.size();
    }
};