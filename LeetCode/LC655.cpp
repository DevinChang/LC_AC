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
    vector<vector<string>> ans;

    vector<int> dfs(TreeNode* root) {
        if (!root) return {0, 0};
        auto l = dfs(root->left), r = dfs(root->right);
        return {max(l[0], r[0]) + 1, max(l[1], r[1]) * 2 + 1};;
    }

    void print(TreeNode* root, int h, int l, int r) {
        if (!root) return;
        int mid = (l + r) / 2;
        ans[h][mid] = to_string(root->val);
        print(root->left, h + 1, l, mid - 1);
        print(root->right, h + 1, mid + 1, r);
    }

    vector<vector<string>> printTree(TreeNode* root) {
        auto t = dfs(root);
        int h = t[0], w = t[1];
        ans = vector<vector<string>>(h, vector<string>(w));
        print(root, 0, 0, w - 1);
        return ans;
    }
};