class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> f(amount+1, 0);
        f[0] = 1;
        for(auto x : coins) {
            for(int i = x; i <= amount; i++) f[i] += f[i - x];
        }
        return f[amount];
    }
};