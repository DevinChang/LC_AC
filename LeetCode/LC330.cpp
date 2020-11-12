class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long x = 1;
        int i = 0, res = 0;
        while(x <= n){
            if(i < nums.size() && nums[i] <= x) x += nums[i++];
            else {
                x += x;
                res++;
            }
        }
        return res;
    }
};