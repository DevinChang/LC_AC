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
    string res;

    string tree2str(TreeNode* t) {
        dfs(t);
        return res;
    }

    void dfs(TreeNode* t) {
        if(t == nullptr) return;
        res += to_string(t->val);
        if(t->left || t->right) {
            res += '(';
            dfs(t->left);
            res += ')';
        }
        if(t->right){
            res += '(';
            dfs(t->right);
            res += ')';
        }
    }
};