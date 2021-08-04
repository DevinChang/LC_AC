/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* get_tail(ListNode *p) {
		while(p->next) p = p->next;
		return p;
	}
    ListNode* quickSortList(ListNode* head) {
		if(!head || !head->next) return head;
		ListNode *left = new ListNode(-1), *mid = new ListNode(-1), *right = new ListNode(-1);
		ListNode *tleft = left, *tmid = mid, *tright = right;
		int val = head->val;
		for(auto p = head; p; p = p->next) {
			if(p->val < val) tleft = tleft->next = p;	
			else if(p->val == val) tmid = tmid->next = p;
			else tright = tright->next = p;
		}
		tleft->next = tmid->next = tright->next = nullptr;
		left->next = quickSortList(left->next);
		right->next = quickSortList(right->next);

		get_tail(left)->next = mid->next;
		get_tail(left)->next = right->next;

		auto p = left->next;
		delete left;
		delete mid;
		delete right;
		return p;
    }
};