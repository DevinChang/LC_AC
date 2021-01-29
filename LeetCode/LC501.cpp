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
    vector<int> res;
    int curn = 0, maxn = 0, last;
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return res;
    }
    void dfs(TreeNode *root) {
        if(!root) return;
        dfs(root->left);
        if(!curn || root->val == last) {
            curn++;
            last = root->val;
        } else {
            curn = 1;
            last = root->val;
        }
        if(curn > maxn) {
            res = {last};
            maxn = curn;
        } else if(curn == maxn) {
            res.push_back(last);
        }
        dfs(root->right);
    }
};