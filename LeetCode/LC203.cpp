


ListNode* removeElements(ListNode* head, int val) {
    if (head == nullptr) return head;
    ListNode *dummy = new ListNode(-1);
    ListNode *tail = dummy, *cur = head;
    while(cur) {
        while(cur->val == val && cur->next){
            cur = cur->next;
        }
        if(cur->val == val && cur->next == nullptr){ 
            tail->next = nullptr; 
            break;
        }
        tail->next = cur;
        tail = cur;
        cur = cur->next;
    }
    return dummy->next;
}