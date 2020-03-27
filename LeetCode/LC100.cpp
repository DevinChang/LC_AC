#include "util.h"


int isSame = -1;

void preOrder(TreeNode *p, TreeNode *q){
    if(isSame == 0)
        return;
    if(p == nullptr && q == nullptr)
        return;
    if(p == nullptr || q == nullptr){
        isSame = 0;
        return;
    }
    if(p->val != q->val){
        isSame = 0;
        return;
    }
    else
        isSame = 1;
    preOrder(p->left, q->left);
    preOrder(p->right, q->right);

}

bool isSameTree_v1(TreeNode* p, TreeNode* q) {
    if(p == nullptr && q== nullptr)
        return true;
    if(p == nullptr || q == nullptr)
        return false;
    preOrder(p, q);
    return isSame == 1;
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == nullptr && q == nullptr)
        return true;
    if(p == nullptr || q == nullptr)
        return false;
    if(p->val != q->val)
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}




int main(){
    string line;
    while(getline(cin, line)){
        TreeNode *p = stringToTreeNode(line);
        getline(cin, line);
        TreeNode *q = stringToTreeNode(line);

        bool ret = isSameTree(p, q);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}