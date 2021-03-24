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
    unordered_set<int> hash;

    bool findTarget(TreeNode* root, int k) {
        return dfs(root, k);        
    }

    bool dfs(TreeNode* root, int k) {
        if(root == nullptr) return false;
        if(dfs(root->left, k)) return true;
        if(hash.count(k - root->val)) return true;
        hash.insert(root->val);
        return dfs(root->right, k);
    }
};