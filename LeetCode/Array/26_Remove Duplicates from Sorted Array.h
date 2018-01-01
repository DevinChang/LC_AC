#include <iostream>
#include <vector>




int removeDuplicates(std::vector<int> &nums){
	int num_duplicates = 0;
	//ע������д�����Ƚϵ�ʱ��Ӧ�ôӺ���ǰ�Ƚ�
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