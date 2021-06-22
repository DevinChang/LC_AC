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
    int rangeSumBST(TreeNode* root, int low, int high) {
		if(root == nullptr) return 0;
		int val = root->val;
		if(val >= low && val <= high)
			return val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
		if(val < low)
			return rangeSumBST(root->right, low, high);
		else 
			return rangeSumBST(root->left, low, high);
    }
};