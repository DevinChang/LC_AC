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
    ListNode* swapPairs(ListNode* head) {
		ListNode *dummy = new ListNode(-1);
		dummy->next = head;
		auto pre = dummy;
		while(pre->next && pre->next->next) {
			auto cur = pre->next, next = cur->next;
			pre->next = next;
			cur->next = next->next;
			next->next = cur;
			pre = cur;
		}
		return dummy->next;
    }
};