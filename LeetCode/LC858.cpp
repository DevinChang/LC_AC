class Solution {
public:
    int gcd(int a, int b){
        return b ? gcd(b, a % b) :a;
    }
    int mirrorReflection(int p, int q) {
        int Y = p * q / gcd(p, q);
        int x = Y / q, y = Y / p;
        if(x % 2) {
            if(y % 2) return 1;
            return 0;
        }
        return 2;
    }
};