/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

#include <iostream>
#include <vector>
#include <unordered_map>




std::vector<int> twosum(std::vector<int> &numbers, int target) {
	std::unordered_map<int, int> hash;
	std::vector<int> re;
	for (int i = 0; i < numbers.size(); ++i) {
		int sub = target - numbers[i];
		//hash[numbers[i]] = i;
		if (hash.find(sub) != hash.end()) {
			re.push_back(hash[sub]);
			re.push_back(i);
		}
		hash[numbers[i]] = i;
	}
	return re;
}

//std::vector<int> twosum2(std::vector<int> &nums, int target) {
//	std::unordered_map<int, int> hash;
//	std::vector<int> re;
//	int i = 0;
//	for (auto p : nums)
//		hash[p] = i++;
//	for (i = 0; i < nums.size(); ++i) {
//		int sub = target - nums[i];
//		if (hash.find(sub) != hash.end()) {
//			re.push_back(hash[sub]);
//			re.push_back(i);
//		}
//	}
//	return re;
//}