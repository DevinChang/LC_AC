

ListNode *getIntersectionNode(ListNode *headA, ListNode* headB){
    ListNode *p = headA, *q = headB;
    while(q != p) {
        if(p) p = p->next;
        else p = headB;
        if(q) q = q->next;
        else q = headA;
    }
    return p;
}


ListNode *getIntersectionNode(ListNode *headA, ListNode* headB){
    if (headA == nullptr || headB == nullptr) return nullptr;
    int lenA = 0, lenB = 0;
    ListNode *curA = headA, *curB = headB;
    while(curA){
        lenA++;
        curA = curA->next;
    }
    while(curB){
        lenB++;
        curB = curB->next;
    }
    if(lenA < lenB) return getIntersectionNode(headB, headA);
    int dit = lenA - lenB;
    curA = headA;
    while(dit--) curA = curA->next;
    curB = headB;
    while(curA || curB){
        if(curA == curB) return curA;
        curA = curA->next;
        curB = curB->next;
    }
    return nullptr;
}