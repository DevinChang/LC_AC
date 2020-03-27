//
// Created by devinchang on 2019/12/12.
//

#include "util.h"


vector<vector<int>> levelOrderBottom(TreeNode *root){
    if(root == nullptr)
        return {};
    queue<TreeNode*> que;
    que.push(root);
    vector<vector<int>> ret;
    stack<vector<int>> s;
    while(!que.empty()){
        int len = que.size();
        TreeNode *p = nullptr;
        vector<int> vec;
        for(int i = 0; i < len; i++){
            p = que.front();
            que.pop();
            vec.push_back(p->val);
            if(p->left)
                que.push(p->left);
            if(p->right)
                que.push(p->right);
        }
        s.push(vec);
    }
    while(!s.empty()){
        vector<int> vec = s.top();
        s.pop();
        ret.push_back(vec);
    }
    return ret;
}


int main(){

    return 0;
}

