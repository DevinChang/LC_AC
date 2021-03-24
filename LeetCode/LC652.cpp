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
    vector<TreeNode*> res;
    int cnt = 0;
    unordered_map<string, int> hash;

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return res;        
    }

    string dfs(TreeNode* root) {
        if(root == nullptr) return "";
        string left = dfs(root->left);
        string right = dfs(root->right);
        string key = to_string(root->val) + " " + left + " " + right;
        hash[key]++;
        if(hash[key] == 2) res.push_back(root);
        return key;
    }
};