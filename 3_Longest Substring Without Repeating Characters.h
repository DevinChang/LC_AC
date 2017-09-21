#pragma once

/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <vector>
#include <string>

#define max(a, b) ((a) > (b) ? (a) : (b))


int lengthOfLongestSubstring(std::string s) {
	std::vector<int> dict(256, -1);
	int maxlen = 0, start = -1;
	for (int i = 0; i < s.size(); ++i) {
		if (dict[s[i]] > start)
			start = dict[s[i]];
		dict[s[i]] = i;
		maxlen = max(maxlen, i - start);
	}
	return maxlen;
}

