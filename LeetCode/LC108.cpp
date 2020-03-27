//
// Created by devinchang on 2019/12/12.
//

#include "util.h"


TreeNode *sortedArrayToBST(vector<int> &nums, int start, int end){
    if(start == end)
        return nullptr;
    int mid = start + (end - start) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBST(nums, start, mid);
    root->right = sortedArrayToBST(nums, mid+1, end);
    return root;
}


TreeNode *sortedArrayToBST(vector<int> &nums){
    if(nums.size() < 1)
        return nullptr;
    return sortedArrayToBST(nums, 0, nums.size());
}



int main(){
    string line;
    while(getline(cin, line)){
        vector<int> nums = stringToIntegerVector(line);

        TreeNode *ret = sortedArrayToBST(nums);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}

