/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/



struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(0), next(nullptr){}
};


ListNode *addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode *p1 = l1, *p2 = l2;
	ListNode *p;
	int carry = 0;
	while (p1 != nullptr || p2 != nullptr) {
		int x = (p1 != nullptr) ? p1->val : 0;
		int y = (p2 != nullptr) ? p2->val : 0;
		int digit = carry + x + y;
		carry = digit / 10;
		p = new ListNode(digit % 10);
		p = p->next;
		l1 = (l1 != nullptr) ? l1->next : l1;
		l2 = (l2 != nullptr) ? l2->next : l2;
	}
	return p;
}