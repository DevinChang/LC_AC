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
    bool dfs(TreeNode* root) {
        if(root == nullptr) return false;
        if(!dfs(root->left)) root->left = nullptr;
        if(!dfs(root->right)) root->right = nullptr;
        return root->val || root->left || root->right;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!dfs(root)) return nullptr;
        return root;
    }
};