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
    ListNode* findKthToTail(ListNode* pListHead, int k) {
        int len = 0;
        ListNode *p = pListHead, *fast = pListHead;
        while(p) p = p->next, len++;
        p = pListHead;

        if(len < k) return nullptr;

        for(int i = 0; i < k && fast != nullptr; i++) fast = fast->next;
        
        while(fast){
            p = p->next;
            fast = fast->next;
        }

        return p;
    }
};