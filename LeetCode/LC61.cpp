/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
		if(!head) return head;
		int n = 0;
		ListNode* tail = head;
		for(auto p = head; p;)  {
			n++;
			tail = p;
			p = p->next;
		}
        
		k %= n;
        
		auto cur = head;
		for(int i = 0; i < n - k - 1; i++) cur = cur->next;
        
		tail->next = head;
		head = cur->next;
		cur->next = nullptr;
		return head;
    }
};