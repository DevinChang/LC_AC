class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> hash;
        for(int x : answers) hash[x]++;
        int res = 0;
        for(auto [k, v] : hash) {
            if(v % (k + 1) == 0) res += v;
            else res += (v / (k+1) + 1) * (k + 1);
        }
        return res;
    }
};