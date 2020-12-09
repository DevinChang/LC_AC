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
    int res = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root);
        return res;
    }

    void dfs(TreeNode *root) {
        if(!root) return;
        if(root->left){
            if(!root->left->left && !root->left->right) res += root->left->val;
        }
        dfs(root->left);
        dfs(root->right);
    }
};