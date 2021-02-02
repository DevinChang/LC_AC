class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 1) return false;
        int total = 0;
        for(int i = 2; i * i <= num; i++) {
            if(num % i == 0) {
                total += i;
                if(i * i != num) total += num / i;
            }
        }
        return total + 1 == num;
    }
};