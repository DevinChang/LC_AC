/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
单链表快速排序
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    ListNode *getTail(ListNode *head){
        while(head->next) head = head->next;
        return head;
    }
public:
    ListNode* quickSortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *left = new ListNode(-1), *right = new ListNode(-1), *mid = new ListNode(-1);

        ListNode *ltail = left, *mtail = mid, *rtail = right;
        int val = head->val;
        for(auto p = head; p; p = p->next){
            if(p->val < val)  ltail = ltail->next = p;
            else if(p->val == val) mtail = mtail->next = p;
            else rtail = rtail->next = p;
        }

        ltail->next = mtail->next = rtail->next = nullptr;
        left->next = quickSortList(left->next) ;
        right->next = quickSortList(right->next);

        getTail(left)->next = mid->next;
        getTail(mid)->next =  right->next;

        auto p = left->next;
        delete left;
        delete mid;
        delete right;
        return p;
    }
};