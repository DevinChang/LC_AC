#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverse(ListNode *head) {
    if(head == nullptr) return head;
    ListNode *cur = head;
    ListNode *dummy = new ListNode(-1);
    while(cur) { 
        ListNode *next = cur->next;
        cur->next = dummy->next;
        dummy->next = cur;
        cur = next;
    }
    return dummy->next;
}

void reorderList(ListNode* head) {
    if (!head) return;
    int n = 0;
    for (auto p = head; p; p = p->next) n ++ ;

    auto mid = head;
    for (int i = 0; i < (n + 1) / 2 - 1; i ++ ) mid = mid->next;
    auto a = mid, b = a->next;
    for (int i = 0; i < n / 2; i ++ ) {
        auto c = b->next;
        b->next = a, a = b, b = c;
    }
    auto p = head, q = a;
    for (int i = 0; i < n / 2; i ++ ) {
        auto o = q->next;
        q->next = p->next;
        p->next = q;
        p = q->next, q = o;
    }

    if (n % 2) mid->next = NULL;
    else mid->next->next = NULL;
}

