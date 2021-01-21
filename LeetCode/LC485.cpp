class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) continue;
            int j = i + 1; 
            while(j < n && nums[j] == 1) j++;
            res = max(res, j - i);
            i = j;
        }
        return res;
    }
};