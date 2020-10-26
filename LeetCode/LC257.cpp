
vector<string> ret;
vector<int> path;

void dfs(TreeNode *root){
    path.push_back(root->val);
    if(root->left == nullptr && root->right == nullptr) {
        string p = to_string(path[0]);
        int n = path.size();
        for(int i = 1; i < n; i++){
            p += "->" + to_string(path[i]);
        }
        ret.push_back(p);
    }
    else {
        if(root->left) dfs(root->left);
        if(root->right) dfs(root->right);
    }
    path.pop_back();
}

vector<string> binaryTreePaths(TreeNode* root) {
    if(root)
        dfs(root);
    return ret;
}