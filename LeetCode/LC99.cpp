//
// Created by devinchang on 2019/12/11.
//

#include "util.h"
using namespace std;

TreeNode *firstNode = nullptr;
TreeNode *secondeNode = nullptr;
TreeNode *preNode = new TreeNode(INT_MIN);


void inOrder(TreeNode *root){
    if(root == nullptr)
        return;
    inOrder(root->left);
    // do
    if(firstNode == nullptr && preNode->val > root->val){
        firstNode = preNode;
    }
    if(firstNode != nullptr && preNode->val > root->val){
        secondeNode = root;
    }
    preNode = root;
    inOrder(root->right);
}

void TreePrint(TreeNode *root){
    if(root == nullptr)
        return;
    TreePrint(root->left);
    cout << root->val << " ";
    TreePrint(root->right);
}


void recoverTree(TreeNode *root){
    if(root == nullptr)
        return;
    //TreePrint(root);
    inOrder(root);
    int val = firstNode->val;
    firstNode->val = secondeNode->val;
    secondeNode->val = val;
    //TreePrint(root);
}



int main(){
    string line;
    //freopen("poj2456.txt", "r", stdin);
    while(getline(cin, line)){
        TreeNode *root = stringToTreeNode(line);
        recoverTree(root);
        string out = treeNodeToString(root);
        cout << out << endl;
    }
    return 0;
}
