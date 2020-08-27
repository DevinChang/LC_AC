#include <iostream>
using namespace std;





ListNode *sortList(ListNode *head) {
    if (head == nullptr) return head;
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    int n = 0;
    ListNode *cur = head;
    while(cur){
        cur = cur->next;
        n++;
    }
    for(int i = 1; i < n; i *= 2){
        cur = dummy;
        for(int j = 1; j + i <= n; j += i*2){
            ListNode *p = cur->next, *q = p;
            for(int k = 0; k < i; k++) q = q->next;
            int x = 0, y = 0;
            while(x < i && y < i && q && p){
                if(p->val <= q->val){
                    cur->next = p;
                    cur = p;
                    p = p->next;
                    x++;
                }
                else {
                    cur->next = q;
                    cur = q;
                    q = q->next;
                    y++;
                }
            }
            while(x < i && p) cur->next = p, cur = p, p = p->next, x++;
            while(y < i && q) cur->next = q, cur = q, q = q->next, y++;
            cur->next = q;
        }
    }
    return dummy->next;
}