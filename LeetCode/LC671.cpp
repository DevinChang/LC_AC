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
    long long min1, min2;

    void dfs(TreeNode* root) {
        if(root == nullptr) return;
        int x = root->val;
        if(x < min1) min2 = min1, min1 = x;
        else if(x > min1 && x < min2) min2 = x;
        dfs(root->left);
        dfs(root->right);
    }

    int findSecondMinimumValue(TreeNode* root) {
        min1 = min2 = 1e18;
        dfs(root);
        if(min2 == 1e18) min2 = -1;
        return min2;
    }
};