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
    TreeNode* build(const vector<int>& nums, int l, int r) {
        if(l > r) return nullptr;
        int max_num = nums[l], max_i = l;
        for(int i = l + 1; i <= r; i++) {
            if(max_num < nums[i]) {
                max_num = nums[i];
                max_i = i;
            }
        }
        TreeNode *rt = new TreeNode(max_num);
        rt->left = build(nums, l, max_i-1);
        rt->right = build(nums, max_i+1, r);
        return rt;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size()-1);
    }
};