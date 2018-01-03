#include <iostream>
#include <vector>
//#include "4_MedianOfTwoSortedArrays.h"
//#include "test.h"
//#include "16_3SumCloset.h"
//#include "18_4Sum.h"
//#include "Array/26_Remove Duplicates from Sorted Array.h"
#include "27_Remove_Element.h"


int main(){
	/*std::vector<int> v1{ 1, 2 }, v2{ 3, 4 };
	auto mid = findMedianSortedArrays(v1, v2);
	if (mid != ERRORCODE)
	std::cout << "the median of the sorted array: " << mid << std::endl;
	else
	std::cout << "Error!!!" << std::endl;*/

	//std::cout << "test: " << test(2.0, 3.0) << std::endl;
	/*std::vector<int> vec{ -1, 1, 2, -4 };
	std::cout << "3 sum closet : " << std::endl;
	std::cout << threeSumClosest(vec, 1) << std::endl;
	*/
	/*
	std::vector<int> s{ 1, 0, -1, 0, -2, 2 };
	auto vec = fourSum(s, 0);
	std::cout << "4 sum: " << std::endl;
	for (auto v : vec){
		for (auto p : v){
			std::cout << p << " ";
		}
		std::cout << std::endl;
	}
	
	std::vector<int> vec{ 1, 1, 1, 2, 2, 3};
	std::cout << removeDuplicates(vec) << std::endl;
	*/
	std::vector<int> vec{ 3, 2, 2, 3 };
	std::cout << removeElement(vec, 3) << std::endl;
	system("pause");
	return 0;
}