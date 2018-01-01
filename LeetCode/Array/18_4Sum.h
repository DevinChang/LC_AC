#include <iostream>
#include <vector>
#include <algorithm>

/*Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
[-1,  0, 0, 1],
[-2, -1, 1, 2],
[-2,  0, 0, 2]	
]*/

/*
class Solution {
	void threeSum(vector<int>& nums, int target, int left, vector<vector<int>> &results) {
		for (int i = left; i < nums.size() - 2; ++i) {
			if ((i != left && nums[i] == nums[i - 1]) || nums[i] + nums.back() * 2 < target || nums[i] * 3 > target) {
			continue;
		}

		int l = i + 1, r = nums.size() - 1;
		while (l < r) {
			int sum = nums[i] + nums[l] + nums[r];
			if (sum == target) {
				results.push_back({nums[left - 1], nums[i], nums[l], nums[r]});
				++l;
				--r;
			} else if (sum < target) {
				++l;
			} else {
				--r;
			}

			while (l != i + 1 && l < r && nums[l] == nums[l - 1]) {
				++l;
			}

			while (r != nums.size() - 1 && l < r && nums[r] == nums[r + 1]) {
				--r;
			}
		}
	  }
	}
public:
vector<vector<int>> fourSum(vector<int>& nums, int target) {
vector<vector<int>> results;

if (nums.size() < 4) return results;

sort(nums.begin(), nums.end());

for (int i = 0; i < nums.size() - 3; ++i) {
if ((i != 0 && nums[i] == nums[i - 1]) || nums[i] + nums.back() * 3 < target || nums[i] * 4 > target) {
continue;
}
threeSum(nums, target - nums[i], i + 1, results);
}

return results;
}
};
*/

std::vector <std::vector<int>> fourSum(std::vector<int> &nums, int target){
	std::vector<std::vector<int>> total;
	std::vector<int> vec(nums.begin(), nums.end());
	std::sort(vec.begin(), vec.end());
	int n = nums.size();
	if (nums.size() < 4) return total;
	for (int i = 0; i < n - 3; ++i){
		if (i > 0 && vec[i] == vec[i - 1]) continue;
		if (vec[i] + vec[i + 1] + vec[i + 2] + vec[i + 3] > target) break;
		if (vec[i] + vec[n - 1] + vec[n - 2] + vec[n - 3] < target) continue;
		for (int j = i + 1; j < n - 2; ++j){
			if (j > i + 1 && vec[j] == vec[j - 1]) continue;
			if (vec[i] + vec[j] + vec[j + 1] + vec[j + 2] > target) break;
			if (vec[i] + vec[j] + vec[n - 1] + vec[n - 2] < target) continue;
			int left = j + 1, right = n - 1;
			while (left < right){
				int sum = vec[i] + vec[j] + vec[left] + vec[right];
				if (sum < target)
					++left;
				else if (sum > target)
					--right;
				else{
					total.push_back(std::vector<int> {vec[i], vec[j], vec[left], vec[right]});
					do{ left++; } while (vec[left] == vec[left - 1] && left < right);
					do{ right--; } while (vec[right] == vec[right + 1] && left < right);
				}
			}
		}
	}
	return total;
}