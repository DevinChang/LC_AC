class Solution {
public:
    int get(vector<int>& piles, int mid) {
        int res = 0;
        for(auto x : piles) {
            // 求a/b的上取整等价于求(a+b-1)/b的下取整
            res += (x + mid - 1) / mid;
        }
        return res;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1e9;
        while(l < r) {
            int mid = l + r >> 1;
            if(get(piles, mid) <= h) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};