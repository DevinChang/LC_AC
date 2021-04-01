/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res;
    int dfs(TreeNode* root) {
        if(root == nullptr) return 0;
        int l = dfs(root->left), r = dfs(root->right);
        if(root->left == nullptr || root->left->val != root->val) l = 0;
        if(root->right == nullptr || root->right->val != root->val) r = 0;
        res = max(res, l + r);
        return max(l, r)+1;
    }
    int longestUnivaluePath(TreeNode* root) {
        res = 0;
        dfs(root);
        return res;
    }
};