/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int res = INT_MAX, last;
    bool is_first = true;
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return res; 
    }

    void dfs(TreeNode *root) {
        if(root == nullptr) return;
        dfs(root->left);
        if(is_first) is_first = false;
        else res = min(res, root->val - last);
        last = root->val;
        dfs(root->right);
    }
};