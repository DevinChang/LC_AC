class Solution {
public:
    typedef long long LL;

    bool check(vector<int>& nums, int mid, int m) {
        int sum = 0, cnt = 0;
        for (auto x: nums) {
            if (x > mid) return false;
            if (sum + x > mid) {
                cnt ++ ;
                sum = x;
            } else {
                sum += x;
            }
        }
        if (sum) cnt ++ ;
        return cnt <= m;
    }


    int splitArray(vector<int>& nums, int m) {
        int l = 0, r = INT_MAX; 
        while(l < r) {
            int mid = (LL)l + r >> 1;
            if(check(nums, mid, m)) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};