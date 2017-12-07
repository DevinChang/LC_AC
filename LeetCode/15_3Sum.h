#include <vector>
#include <algorithm>



std::vector<std::vector<int>> treeSum(std::vector<int> &nums) {
	std::vector<std::vector<int>> res;
	std::sort(nums.begin(), nums.end());

	for (int i = 0; i < nums.size(); i++) {
		int target = -nums[i];
		int front = i + 1;
		int back = nums.size() - 1;

		while (front < back) {
			int sum = nums[front] + nums[back];
			if (sum < target)   
				front++;
			else if (sum > target)
				back--;
			else {
				std::vector<int> triplet(3, 0);
				triplet[0] = nums[i];
				triplet[1] = nums[front];
				triplet[2] = nums[back];
				res.push_back(triplet);
				while (front < back && nums[front] == triplet[1]) front++;
				while (front < back && nums[back] == triplet[2]) back--;

			}
		}
		while (i + 1 < nums.size() && nums[i + 1] == nums[i])
			i++;
	}
}