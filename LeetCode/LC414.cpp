class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int cnt = 0;
        long long INF = 1e10;
        long long a = -INF, b = -INF, c = -INF;
        for(auto x : nums) {
            if(x > a) c = b, b = a, a = x, cnt++;
            else if (x > b && x < a) c = b, b = x, cnt++;
            else if (x > c && x < b) c = x, cnt++;
        }
        if (cnt < 3) return a;
        return c;
    }
};