#include <vector>
#include <algorithm>

/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
[-1, 0, 1],
[-1, -1, 2]
]
*/

//2017/12/26 modify: 通过增加一些边界条件，减少循环的次数，从而减少运行的时间
std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
	std::vector<std::vector<int>> res;
	std::sort(nums.begin(), nums.end());
	
	for (int i = 0; i < nums.size(); ++i){
		if (nums[i] > 0) break;
		if (i > 0 && nums[i] == nums[i - 1]) continue;
		int target = -1 * nums[i];
		int left = i + 1, right = nums.size() - 1;
		while (left < right){
			if (nums[left] + nums[right] == target){
				res.push_back(std::vector<int>{nums[i], nums[left++], nums[right--]});
				while (left < right && nums[left] == nums[left - 1])
					left++;
				while (left < right && nums[right] == nums[right + 1])
					right--;
			}
			else if (nums[left] + nums[right] < target)
				left++;
			else
				right--;
		}
	}
	return res;
}