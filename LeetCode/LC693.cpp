class Solution {
public:
    bool hasAlternatingBits(int n) {
        for(int i = 1; 1ll << i <= n; i++) {
            int a = n >> i - 1 & 1;
            int b = n >> i & 1;
            if (a == b) return false;
        }
        return true;
    }
};