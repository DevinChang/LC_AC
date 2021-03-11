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
    const int P = 131, Q = 159, MOD = 1e7 + 7, NULLRES=12345;
    int T = -1;
    bool ans = false;

    int dfs(TreeNode* root) {
        if(!root) return NULLRES;
        int left = dfs(root->left), right = dfs(root->right);
        // 保证不为负数
        int x = (root->val % MOD + MOD) % MOD;
        if(left == T || right == T) ans = true;
        return (x + left * P % MOD + right * Q) % MOD;
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        T = dfs(t);
        if(T == dfs(s)) ans = true;
        return ans;
    }
};