//
// Created by devinchang on 2019/12/11.
//

#include "util.h"

vector<vector<int>> zigzagLevelOrder(TreeNode *root){
    if(root == nullptr)
        return {{}};
    int level = 1;
    queue<TreeNode*> que;
    que.push(root);
    vector<vector<int>> ret;
    while(!que.empty()){
        int size = que.size();
        TreeNode *p = nullptr;
        vector<int> vec;
        for(int i = 0; i < size; i++){
            p = que.front();
            que.pop();
            if(p->left)
                que.push(p->left);
            if(p->right)
                que.push(p->right);
            vec.push_back(p->val);
        }
        if(level++ % 2 == 1)
            ret.push_back(vec);
        else
            ret.push_back(vector<int>(vec.rbegin(), vec.rend()));
    }
    return ret;
}


int main(){


    return 0;
}

