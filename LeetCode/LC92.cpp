#include <bits/stdc++.h>
using namespace std;


struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr){}
};

ListNode* reverseBetween(ListNode* head, int m, int n) {
    if(head == nullptr || m < 1 || n < 1)
        return head;
    ListNode *headPre = nullptr, *pre = nullptr, *cur = nullptr, *r = nullptr;
    ListNode *headEnd = nullptr;
    ListNode *p = head;
    int step = n-m;
    int i = 1;
    for(; i < m; i++){
        headPre = p;
        p = p->next;
    }
    cur = p, r = cur->next;
    for(; i < n; i++){
        p = p->next;
    }
    headEnd = p->next;
    cur->next = headEnd;
    for(int i = 0; i < step; i++){
        pre = cur;
        cur = r;
        r = r->next;
        cur->next = pre;
    }
    if(headPre)
        headPre->next = cur;
    else
        head = cur;
    return head;
}



int main(){
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    ListNode *node6 = new ListNode(3);
    ListNode *node7 = new ListNode(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    node6->next = node7;

    reverseBetween(node6, 1, 2);

    ListNode *p = node1;
    while(p){
        std::cout << p->val << " ";
        p = p->next;
    }
}