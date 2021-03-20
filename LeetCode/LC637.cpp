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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(root == nullptr) return res;
        queue<TreeNode*> que;
        que.push(root);
        while(que.size()) {
            double sum = 0;
            int sz = que.size();
            for(int i = 0; i < sz; i++) {
                auto t = que.front();
                que.pop();
                sum += t->val;
                if(t->left) que.push(t->left);
                if(t->right) que.push(t->right);
            }
            res.push_back(sum / sz);
        }
        return res;
    }
};