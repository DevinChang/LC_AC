#include <iostream>
#include <algorithm>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
public:
    ListNode *reverseList(ListNode *head){
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *tail = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return tail;
    }

    ListNode* reverseList_Iter(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *pre = nullptr, *cur = head;
        while(cur){
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};