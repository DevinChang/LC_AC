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
    ListNode* removeNthFromEnd(ListNode* head, int k) {
		int n = 0;
		for(ListNode* cur = head; cur; cur = cur->next) n++;

		if(n == k) return head->next;

		int cnt = 0;
		for(ListNode* cur = head; cur; cur = cur->next) {
			cnt++;
			if(cnt == n - k) {
				cur->next = cur->next->next;
			}	
		}
		return head;
    }
};