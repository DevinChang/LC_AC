class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(auto x : nums) {
            x = abs(x);
            if(nums[x-1] > 0) nums[x-1] *= -1;
        }
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) res.push_back(i+1);
        }
        return res;
    }
};