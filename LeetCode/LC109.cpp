//
// Created by devinchang on 2019/12/12.
//

#include "util.h"





ListNode *findMidNode(ListNode *head){
    if(head == nullptr)
        return nullptr;
    ListNode *pre = nullptr, *slow = head, *fast = head;
    while(fast != nullptr && fast->next != nullptr){
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(pre != nullptr)
        pre->next = nullptr;
    return slow;
}

TreeNode *sortedListToBST(ListNode *head){
    if(head == nullptr)
        return nullptr;
    ListNode *mid = findMidNode(head);

    TreeNode *root = new TreeNode(mid->val);
    if(mid == head)
        return root;

    root->left = sortedListToBST(head);
    root->right = sortedListToBST(mid->next);
    return root;
}

int main(){
    string line;
    while(getline(cin, line)){
        ListNode *head = stringToListNode(line);
        TreeNode *ret = sortedListToBST(head);

        string out = treeNodeToString(ret);

        cout << out << endl;
    }
    return 0;
}

