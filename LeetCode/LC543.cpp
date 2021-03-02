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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;    
        dfs(root, ans);
        return ans;
    }

    int dfs(TreeNode* root, int& ans) {
        if(root == nullptr) return 0;
        int left = dfs(root->left, ans);
        int right = dfs(root->right, ans);
        ans = max(ans, left + right);
        return max(left, right) + 1;
    }
};