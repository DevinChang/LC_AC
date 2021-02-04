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
    unordered_map<int,int> hash;
    int maxd = 0;
    vector<int> largestValues(TreeNode* root) {
        dfs(root, 1);
        vector<int> res;
        for(int i = 1; i <= maxd; i++) {
            res.push_back(hash[i]);
        }
        return res;
    }

    void dfs(TreeNode* root, int d) {
        if(!root) return;
        maxd = max(maxd, d);
        if(hash.count(d) == 0) hash[d] = root->val;
        else {
            hash[d] = max(hash[d], root->val);
        }
        dfs(root->left, d+1);
        dfs(root->right, d+1);
    }
};