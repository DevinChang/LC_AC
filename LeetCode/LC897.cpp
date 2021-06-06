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
    TreeNode* tail;

    void dfs(TreeNode *root) {
        if(root == nullptr) return;
        dfs(root->left);
        tail->right = root;
        tail = root;
        root->left = nullptr;
        dfs(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        auto dummy = new TreeNode(-1);
        tail = dummy;
        dfs(root);
        return dummy->right;
    }
};