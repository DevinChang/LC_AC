// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int t = (rand7()-1) * 7 + rand7(); // 生成1-49之间的数
        if(t > 40) return rand10();
        return (t-1) % 10 + 1; 
    }
};