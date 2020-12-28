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
    TreeNode* deleteNode(TreeNode* root, int key) {
        del(root, key);
        return root; 
    }

    void del(TreeNode* &root, int key) {
        if(!root) return;
        if(key == root->val) {
            if(!root->left && !root->right) root = nullptr;
            else if(!root->left) root = root->right;
            else if(!root->right) root = root->left;
            else {
                auto next = root->right;
                while(next->left) next = next->left;
                root->val = next->val;
                del(root->right, next->val);
            }
        }
        else if(key < root->val) del(root->left, key);
        else del(root->right, key);
    }
};