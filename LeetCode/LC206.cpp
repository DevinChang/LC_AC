


ListNode *reverList(ListNode *head) {
    if(head == nullptr) return head;
    ListNode *dummy = new ListNode(-1);
    ListNode *cur = head;
    while(cur) {
        ListNode *next = cur->next;
        cur->next = dummy->next;
        dummy->next = cur;
        cur = next;
    }
    return dummy->next;
}



ListNode *reverseList(ListNode *head){
    if(!head || !head->next) return head;
    ListNode *tail = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return tail;
}