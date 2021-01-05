class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        x = x ^ y;
        while(x) {
            res++;
            x = x & (x - 1);
        } 
        return res;
    }
};