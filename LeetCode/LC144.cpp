#include <iostream>
#include <vector>
#include <stack>
using namespace std;


vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    stack<TreeNode*> stk;
    while(root || stk.size()) {
        while(root){
            res.push_back(root->val);
            stk.push(root);
            root = root->left;
        }
        root = stk.top()->right;
        stk.pop();
    }
    return res;
}



