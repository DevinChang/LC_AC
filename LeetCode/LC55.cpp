class Solution {
public:
    bool canJump(vector<int>& nums) {
		int n = nums.size();
		for(int i = 1, j = 0; i < n; i++) {
			while(j < i && j + nums[j] < i) j++;
			if(j == i) return false;
		}
		return true;
    }
};