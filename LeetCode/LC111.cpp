//
// Created by devinchang on 2019/12/13.
//

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
    int minDepth(TreeNode* root) {
		if(root == nullptr) return 0;
		if(root->left == nullptr && root->right == nullptr) return 1;
		if(root->left && root->right) return min(minDepth(root->left), minDepth(root->right)) + 1;
		if(root->left) return minDepth(root->left) + 1;
		return minDepth(root->right) + 1;
    }
};




