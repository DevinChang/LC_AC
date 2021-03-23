class Solution {
public:
    int minSteps(int n) {
        int res = 0;
        int i = 2;
        while(n > 1) {
            while(n % i == 0) {
                n /= i;
                res += i;
            }
            i++;
        }
        return res;
    }
};