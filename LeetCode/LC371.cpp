class Solution {
public:
    int getSum(int a, int b) {
        if(a == 0) return b;
        int sum = a ^ b;
        int carry = (unsigned)(a & b) << 1;
        return getSum(carry, sum);
    }
};