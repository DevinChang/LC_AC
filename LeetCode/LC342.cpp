class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        int t = sqrt(n);
        return (t * t) == n && ((1 << 30) % n == 0);
    }
};