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
    int res = INT_MAX, last;
    bool is_first = true;

    void dfs(TreeNode* root) {
        if(root == nullptr) return;
        dfs(root->left);
        if(!is_first) res = min(res, root->val - last);
        is_first = false;
        last = root->val;
        dfs(root->right);
    }

    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return res;
    }
};