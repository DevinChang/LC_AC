#include <iostream>
using namespace std;



ListNode *insertionSortList(ListNode *head){
    if (head == nullptr) return head;
    ListNode *dummy = new ListNode(-1);
    while(head){
        ListNode *next = head->next;
        ListNode *cur = dummy;
        while(cur->next && cur->next->val <= head->val) cur = cur->next;
        head->next = cur->next;
        cur->next = head;
        head = next; 
    }
    return dummy->next;
}