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
    int rob(TreeNode* root) {
        auto ret = dfs(root);
        return max(ret[0], ret[1]);
    }


    // 两个状态,第一个状态表示不取节点，第二个表示取当前节点
    vector<int> dfs(TreeNode *root) {
        if(root == nullptr) return {0, 0};
        auto l = dfs(root->left), r = dfs(root->right);
        return {max(l[0], l[1]) + max(r[0], r[1]), l[0] + r[0] + root->val};
    }
};