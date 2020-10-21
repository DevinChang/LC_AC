

bool isPalindrome(ListNode *head){
    int n = 0;
    for(auto p = head; p != nullptr; p = p->next) n++;
    if(n <= 1) return true;
    ListNode *p1 = head, *p2 = head;
    for (int i = 0; i < (n + 1) / 2 - 1; i ++ ) p1 = p1->next;
    p2 = p1->next;
    // reverse
    while(p2){
        ListNode *next = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = next;
    }
    ListNode *tail = p1;
    p2 = head;
    bool res = true;
    for(int i = 0; i < n / 2; i++) {
        if(p1->val != p2->val){
            res = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    p1 = tail, p2 = p1->next;
    for (int i = 0; i < n / 2; i ++ )
    {
        ListNode *next = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = next;
    }
    tail->next = 0;
    return res;
}