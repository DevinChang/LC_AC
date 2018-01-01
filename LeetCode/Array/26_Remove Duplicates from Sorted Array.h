#include <iostream>
#include <vector>




int removeDuplicates(std::vector<int> &nums){
	int num_duplicates = 0;
	//注意这种写法，比较的时候应该从后往前比较
	for (int i = 1; i < nums.size(); ++i) {
		if (nums[i] == nums[i - 1]) {
			++num_duplicates;
		}
		else {
			nums[i - num_duplicates] = nums[i];
		}
	}
	nums.erase(nums.end() - num_duplicates, nums.end()); 
	return nums.size();
}