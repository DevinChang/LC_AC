class Solution {
public:
    int gcd(int x, int y) {
        return y ? gcd(y, x % y) : x;
    }
    bool canMeasureWater(int x, int y, int z) {
        if(x == 0 && y == 0){
            return z == 0;
        }
        if(z > x + y) return false;
        auto g = gcd(x, y);
        return z % g == 0;
    }
};