typedef long long LL;
typedef pair<int, int> PII;

#define x first
#define y second

class Solution {
public:
    LL calc(vector<vector<int>>& rts, int a, int b) {
        vector<PII> q;
        for (auto& r: rts)
            if (r[0] <= a && r[2] >= b)
                q.push_back({r[1], r[3]});
        sort(q.begin(), q.end());
        LL res = 0, st = -1, ed = -1;
        for (auto& r: q)
            if (r.x > ed) {
                res += ed - st;
                st = r.x, ed = r.y;
            } else if (r.y > ed) {
                ed = r.y;
            }
        res += ed - st;
        return res * (b - a);
    }

    int rectangleArea(vector<vector<int>>& rts) {
        vector<int> xs;
        for (auto& r: rts) {
            xs.push_back(r[0]);
            xs.push_back(r[2]);
        }
        sort(xs.begin(), xs.end());

        LL res = 0;
        for (int i = 1; i < xs.size(); i ++ )
            res += calc(rts, xs[i - 1], xs[i]);
        return res % 1000000007;
    }
};