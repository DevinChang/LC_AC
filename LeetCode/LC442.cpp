class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(auto x : nums) {
            int idx = abs(x) - 1;
            nums[idx] *= -1;
            if(nums[idx] > 0) res.push_back(abs(x));
        }
        return res;
    }
};