



bool hasCycle(ListNode *head){
    if(head == nullptr || head->next == nullptr) return false;
    ListNode *slow = head, *fast = slow->next;
    while(slow != fast){
        if(fast->next && fast->next->next) fast = fast->next->next;
        else{ 
            return false;
        }
        slow = slow->next;
    }
    return true;
} 