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
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n % 2 == 0) return {};
        vector<TreeNode*> res;
        if(n == 1) res.push_back(new TreeNode());
        for(int i = 1; i + 1 < n; i += 2) {
            auto left = allPossibleFBT(i);
            auto right = allPossibleFBT(n-i-1);
            for(auto l : left) {
                for(auto r : right)
                    res.push_back(new TreeNode(0, l, r));
            }
        }
        return res;
    }
};