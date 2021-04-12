class Solution {
public:
    int get(vector<int>& nums, int mid) {
        int res = 0;
        for(int i = 0, j = 0; i < nums.size(); i++) {
            while(nums[i] - nums[j] > mid) j++;
            res += i - j;
        }
        return res;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.back() - nums[0];
        while(l < r) {
            int mid = (l + r) >> 1;
            if(get(nums, mid) >= k) r = mid;
            else l = mid +1;
        }
        return r;
    }
};