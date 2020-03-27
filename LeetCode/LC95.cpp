//
// Created by devinchang on 2019/12/20.
//

#include "util.h"

vector<TreeNode*> generateTrees(int start, int end){
    vector<TreeNode*> ret;
    if(start > end){
        ret.push_back(nullptr);
        return ret;
    }
    if(start == end){
        ret.push_back(new TreeNode(start));
        return ret;
    }
    for(int i = start; i <= end; i++){
        vector<TreeNode*> left = generateTrees(start, i-1);
        vector<TreeNode*> right = generateTrees(i+1, end);
        for(auto l : left){
            for(auto r : right){
                TreeNode *root = new TreeNode(i);
                root->left = l;
                root->right = r;
                ret.push_back(root);
            }
        }
    }
    return ret;
}

vector<TreeNode*> generateTrees(int n){
    if(n < 1)
        return {};
    return generateTrees(1, n);
}



int main(){
    vector<TreeNode*> ret = generateTrees(4);
    for(auto r : ret){
        string out = treeNodeToString(r);
        cout << out << endl;
    }
    cout << ret.size() << endl;
    return 0;
}

