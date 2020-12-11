class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> hash;
        for(auto c : s) hash[c]++;
        int res = 0;
        for(auto [c, k] : hash) res += k / 2 * 2;
        if (res < s.size()) res++;
        return res;
    }
};