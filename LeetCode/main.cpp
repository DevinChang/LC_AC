#include <iostream>
#include <vector>
#include "4_MedianOfTwoSortedArrays.h"
#include "test.h"



int main(){
	std::vector<int> v1{ 1, 2 }, v2{ 3, 4 };
	auto mid = findMedianSortedArrays(v1, v2);
	if (mid != ERRORCODE)
		std::cout << "the median of the sorted array: " << mid << std::endl;
	else
		std::cout << "Error!!!" << std::endl;
	//std::cout << "test: " << test(2.0, 3.0) << std::endl;
	system("pause");
	return 0;
}