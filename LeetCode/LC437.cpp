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
    unordered_map<int, int> cnt;
    int res = 0;

    int pathSum(TreeNode* root, int sum) {
        cnt[0]++;
        dfs(root, sum, 0);
        return res;        
    }

    void dfs(TreeNode* root, int sum, int cur) {
        if(!root) return;
        cur += root->val;
        res += cnt[cur-sum];
        cnt[cur]++;
        dfs(root->left, sum, cur);
        dfs(root->right, sum, cur);
        cnt[cur]--;
    }
};