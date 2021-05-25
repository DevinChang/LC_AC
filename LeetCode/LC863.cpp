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
    unordered_map<TreeNode*,vector<TreeNode*>> g;
    vector<int> res;
    
    void dfs1(TreeNode* root){
        if(root->left) {
            g[root].push_back(root->left);
            g[root->left].push_back(root);
            dfs1(root->left);
        }
        if(root->right){
            g[root].push_back(root->right);
            g[root->right].push_back(root);
            dfs1(root->right);
        }
    }

    void dfs2(TreeNode* root, TreeNode* parent, int k){
        if(k == 0) res.push_back(root->val);
        else {
            for(auto& child : g[root]){
                if (child != parent) dfs2(child, root, k-1);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs1(root);        
        dfs2(target, nullptr, k);
        return res;
    }
};