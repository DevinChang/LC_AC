#include "1_TwoSum.h"



int main() {
	//1.twosum
	std::vector<int> numbers{ 3, 3};
	int target = 6;
	auto result = twosum(numbers, target);
	std::cout << "the subscription: ";
	for (auto p : result)
		std::cout << p << " ";
	std::cout << std::endl;
	system("pause");
	return 0;
}