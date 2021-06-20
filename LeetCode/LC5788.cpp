class Solution {
public:
    string largestOddNumber(string num) {
		int k = num.size() - 1;
		while(k >= 0 && num[k] % 2 == 0) k--;
		if(k < 0) return "";
		return num.substr(0, k+1);
    }
};