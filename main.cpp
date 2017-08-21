#include "1_TwoSum.h"
#include "2_AddTwoNumbers.h"


int main() {
	//1.twosum
	/*
	std::vector<int> numbers{ 3, 3};
	int target = 6;
	auto result = twosum(numbers, target);
	std::cout << "the subscription: ";
	for (auto p : result)
		std::cout << p << " ";
	std::cout << std::endl;
	*/

	//2.add two numbers
	ListNode *lhead = new ListNode(9), *l1 = new ListNode(9), *l2 = new ListNode(9);
	lhead->next = l1;
	l1->next = l2;
	ListNode *rhead = new ListNode(1);
	auto rl = addTwoNumbers(lhead, rhead);
	while (rl) {
		std::cout << rl->val << "-> ";
		rl = rl->next;
	}
	system("pause");
	return 0;
}