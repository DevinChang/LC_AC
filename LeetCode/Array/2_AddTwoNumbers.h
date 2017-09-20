/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/



struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr){}
};


ListNode *addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode *p1 = l1, *p2 = l2;
	ListNode phead = ListNode(0);
	ListNode *p = &phead;
	int carry = 0;
	while (p1 != nullptr || p2 != nullptr || carry) {
		int x = (p1 != nullptr) ? p1->val : 0;
		int y = (p2 != nullptr) ? p2->val : 0;
		int digit = carry + x + y;
		carry = digit / 10;
		p->next = new ListNode(digit % 10);
		p = p->next;
		if (p1 != nullptr) p1 = p1->next;
		if (p2 != nullptr) p2 = p2->next;
	}
	return phead.next;
}