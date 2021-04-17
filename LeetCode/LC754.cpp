class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int n = 0, sum = 0;
        while(sum < target || (sum - target) % 2) {
            n++;
            sum += n;
        }
        return n;
    }
};