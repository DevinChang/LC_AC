//
// Created by devinchang on 2019/12/13.
//

#include "util.h"

int depth(TreeNode *root){
    if(root == nullptr)
        return 0;
    int left = depth(root->left);
    if(left == -1)
        return -1;
    int right = depth(root->right);
    if(right == -1)
        return -1;
    return abs(left - right) > 1 ? -1 : max(left, right) + 1;
}

bool isBalanced(TreeNode *root){
    if(root == nullptr)
        return true;
    return depth(root) != -1;
}


int main(){
   string line;
   while(getline(cin, line)){
       TreeNode *root = stringToTreeNode(line);

       bool ret = isBalanced(root);
       string out = boolToString(ret);

       cout << out << endl;
   }

    return 0;
}

