class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != -1) {
                int j = i, s = 0;
                while(nums[j] != -1) {
                    s++;
                    int next = nums[j];
                    nums[j] = -1;
                    j = next;
                }
                res = max(res, s);
            }
        }
        return res;
    }
};