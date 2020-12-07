class Solution {
public:
    typedef long long LL;
    unordered_map<LL, int> hash;
    int integerReplacement(int n) {
        return dfs(n);
    }
    int dfs(LL n) {
        if(hash.count(n)) return hash[n];
        if(n == 1) return 0;
        if(n % 2 == 0) return hash[n] = dfs(n / 2) + 1;
        return hash[n] = min(dfs(n+1), dfs(n-1)) + 1;
    }
};