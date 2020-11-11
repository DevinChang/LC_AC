class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *odd = head, *even = head->next, *even_head = head->next;
        for(ListNode *p = even->next; p;){
            odd->next = p, odd = p, p = p->next;
            if(p){
                even->next = p, even = p, p = p->next;
            }
        }
        odd->next = even_head;
        even->next = nullptr;
        return head;
    }
};