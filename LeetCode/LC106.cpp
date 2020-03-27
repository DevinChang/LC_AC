//
// Created by devinchang on 2019/12/11.
//

#include "util.h"


TreeNode *buildTree(vector<int> &inorder, int instart, int inend, vector<int> &postorder,
                    int postart, int poend){
    if(inend <= instart || poend <= postart)
        return nullptr;
    TreeNode *root = new TreeNode(postorder[poend-1]);

    int index = find(inorder.begin()+instart, inorder.begin()+inend, postorder[poend-1]) - inorder.begin() - instart;

    root->left = buildTree(inorder, instart, instart+index, postorder, postart, postart+index);
    root->right = buildTree(inorder, instart+index+1, inend, postorder, postart + index, poend-1);
    return root;
}


TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder){
    if(inorder.size() < 1 || postorder.size() < 1)
        return nullptr;
    return buildTree(inorder, 0, inorder.size(), postorder, 0, postorder.size());
}


int main(){
    string line;
    while(getline(cin, line)){
        vector<int> inorder = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> postorder = stringToIntegerVector(line);

        TreeNode *ret = buildTree(inorder, postorder);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}

