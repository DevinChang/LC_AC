#pragma once
/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.Return the sum of the three integers.You may assume that each input would have exactly one solution.

For example, given array S = { -1 2 1 - 4 }, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).*/

#include <vector>
#include <numeric>
#include <algorithm>

int threeSumClosest(std::vector<int> &nums, int target) {
	std::vector<int> vec(nums.begin(), nums.end());
	std::sort(vec.begin(), vec.end());
	int sum = 0, n = vec.size();
	if (vec.size() <= 3)
		return std::accumulate(vec.begin(), vec.end(), 0);
	int ans = vec[0] + vec[1] + vec[2];
	for (int i = 0; i < n - 2; ++i){
		int j = i + 1;
		int k = n - 1;
		while (j < k){
			sum = vec[i] + vec[j] + vec[k];
			if (std::abs(target - ans) > std::abs(target - sum)){
				ans = sum;
				if (ans == target)
					return ans;
			}
			sum > target ? k-- : j++;
		}
	}
	return ans;
}