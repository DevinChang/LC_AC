class Solution {
public:
    string get(int x, int y) {
        return to_string(x) + '#' + to_string(y);
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> S;
        for(auto b : obstacles) S.insert(get(b[0], b[1]));
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        int res = 0;
        int x = 0, y = 0, d = 0;
        for(auto c : commands) {
            if (c == -2) d = (d + 3) % 4;
            else if (c == -1) d = (d + 1) % 4;
            else {
                for(int i = 0; i < c; i++) {
                    int a = x + dx[d], b = y + dy[d];
                    if(S.count(get(a, b))) break;
                    x = a, y = b;
                    res = max(res, x * x + y * y);
                }
            }
        }
        return res;
    }
};