//
// Created by devinchang on 2019/12/4.
//
#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

ListNode *deleteDuplicates(ListNode *head){
    if(head == nullptr)
        return head;
    ListNode *ret = new ListNode(-1);
    ret->next = head;
    ListNode *pre = ret, *cur = head;
    while(cur){
        if((cur->next && cur->val != cur->next->val) || cur->next == nullptr){
            if(pre->next == cur)
                pre = cur;
            else
                pre->next = cur->next;
        }
        cur = cur->next;
    }
    return ret->next;
}


int main(){
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(1);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(3);
    ListNode *node5 = new ListNode(4);
    ListNode *node6 = new ListNode(4);
    ListNode *node7 = new ListNode(5);
    node1->next = node2;
    //node2->next = node3;
    //node3->next = node4;
    //node4->next = node5;
    //node5->next = node6;
    //node6->next = node7;

    deleteDuplicates(node1);
    ListNode *cur = node1;
    while(cur){
        cout << cur->val  << " ";
        cur = cur->next;
    }
    return 0;
}

