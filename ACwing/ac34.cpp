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
    ListNode *entryNodeOfLoop(ListNode *head) {
		if(!head || !head->next) return head;
		ListNode *slow = head, *fast = head;
		while(slow && fast) {
			slow = slow->next;
			fast = fast->next;
			if(fast->next) fast = fast->next;
			else return nullptr;
			if(fast == slow) {
				slow = head;
				while(slow != fast) {
					slow = slow->next;
					fast = fast->next;
				}
				return slow;
			}
		}
		return nullptr;
    }
};