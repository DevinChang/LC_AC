class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long i = 0; i * i <= c; i++) {
            int j = sqrt(c - i * i);
            if(j * j + i * i == c) return true;
        }
        return false;
    }
};