class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 0, r = num;
        while(l < r){
            int mid = l + 1ll + r >> 1;
            if(mid <= num / mid) l = mid;
            else r = mid - 1;
        }
        return r * r == num;
    }
};