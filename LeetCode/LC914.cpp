    class Solution {
    public:
        int gcd(int a, int b) {
            return b ? gcd(b, a % b) : a;
        }

        bool hasGroupsSizeX(vector<int>& deck) {
            unordered_map<int, int> cnt;
            for(auto x : deck) cnt[x]++;
            int d = 0;
            for(auto [k, v] : cnt) d = gcd(d, v);
            return d >= 2;
        }
    };