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
    ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode *dummy = new ListNode(-1);
		dummy->next = head;
		auto pre = dummy;
		while(pre != nullptr) {
			auto cur = pre;
			for(int i = 0; i < k && cur != nullptr; i++)  cur = cur->next;
			if(cur == nullptr) break;
			auto p = pre->next;
            auto c = p->next;
			while(p != cur) {
                auto tmp = c->next;
                c->next = p;
                p = c;
                c = tmp;
            }
			auto next = pre->next;
			pre->next = p;
			next->next = c;
            pre = next;
		}
		return dummy->next;
    }
};