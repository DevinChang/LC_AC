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
    unordered_map<int,int> pos;

    TreeNode* build(vector<int>& pre, vector<int>& post, int a, int b, int x, int y) {
        if(a > b) return nullptr;
        auto root = new TreeNode(pre[a]);
        if(a == b) return root;
        int k = pos[pre[a+1]];
        root->left = build(pre, post, a+1, a+1+k-x, x, k);
        root->right = build(pre, post, a+1+k-x+1, b, k+1, y-1);
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        for(int i = 0; i < n; i++) pos[post[i]] = i;
        return build(pre, pos, 0, n-1, 0, n-1);
    }
};