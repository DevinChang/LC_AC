class Solution {
public:
    int dst(vector<int> &a, vector<int> &b) {
        int dx = a[0] - b[0], dy = a[1] - b[1];
        return dx * dx + dy * dy;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> p({p1, p2, p3, p4});
        vector<int> d;
        for(int i = 0; i < 4; i++) {
            for(int j = i + 1; j < 4; j++) {
                d.push_back(dst(p[i], p[j]));
            }
        }
        sort(d.begin(), d.end());
        if(d[0] == 0) return false;
        return d[0] == d[1] && d[0] == d[2] && d[0] == d[3] && d[4] == d[5];
    }
};