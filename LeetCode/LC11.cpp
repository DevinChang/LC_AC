class Solution {
public:
    int maxArea(vector<int>& height) {
		int res = 0, n = height.size();
		for(int i = 0, j = n - 1; i <= j;) {
			res = max(res, min(height[i], height[j]) * (j - i));
			if(height[i] < height[j]) i++;
			else j--;
		}
		return res;
    }
};