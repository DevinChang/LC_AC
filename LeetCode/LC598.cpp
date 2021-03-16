class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int x = m, y = n;
        for(auto p : ops) {
            x = min(x, p[0]);
            y = min(y, p[1]);
        }
        return x * y;
    }
};