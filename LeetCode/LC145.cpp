#include <iostream>
#include <vector>
#include <stack>
using namespace std;



vector<int> postorder(TreeNode*root){
    vector<int> res;
    stack<TreeNode*> stk;
    TreeNode *last = nullptr;
    while(root || stk.size()){
        while(root){
            s.push(root);
            root->left;
        }
        root = s.top();
        if(root->right == nullptr || root->right == last){
            s.pop();
            res.push_back(root->val);
            last = root;
            root = null;
        }
        else{
            root = root->right;
        }
    }
    return res;
}


vector<int> postorderTraversal(TreeNode *root){
    vector<int> res;
    stack<TreeNode*> stk;
    while(root || stk.size()){
        while(root){
            res.push_back(root->val);
            stk.push(root);
            root = root->right;
        }
        root = stk.top()->left;
        stk.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}