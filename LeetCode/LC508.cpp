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
    unordered_map<int,int> hash;
    int maxn = 0;
    vector<int> res;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        return res;
    }

    int dfs(TreeNode* root) {
        if(!root) return 0;
        int sum = root->val + dfs(root->left) + dfs(root->right);
        hash[sum]++;
        if(hash[sum] > maxn) {
            maxn = hash[sum];
            res = {sum};
        }
        else if (hash[sum] == maxn) {
            res.push_back(sum);
        }
        return sum;
    }
};