#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;




/**
 * Definition for a binary tree node.
*/
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
    unordered_map<int, int> pos;

    TreeNode* dfs(vector<int> &preorder, vector<int> &inorder, int pl, int pr, int il, int ir){
        if(pl > pr) return nullptr;
        int k = pos[preorder[pl]] - il;
        TreeNode *root = new TreeNode(preorder[pl]);
        root->left = dfs(preorder, inorder, pl+1, pl+k, il, il+k-1);
        root->right = dfs(preorder, inorder, pl+k+1, pr, il+k+1, ir);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int prelen = preorder.size(), inlen = inorder.size();
        if(prelen != inlen) return nullptr;
        for(int i = 0; i < inlen; i++) pos[inorder[i]] = i;

        return dfs(preorder, inorder, 0, prelen-1, 0, inlen-1);
    }
};