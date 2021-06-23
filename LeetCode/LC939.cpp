class Solution {
public:
    int get(vector<int> p) {
        return p[0] * 50000 + p[1];
    }

    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<int> S;
        for (auto& p: points) S.insert(get(p));
        int res = INT_MAX;
        for (int i = 0; i < points.size(); i ++ )
            for (int j = i + 1; j < points.size(); j ++ ) {
                auto &p = points[i], &q = points[j];
                if (p[0] != q[0] && p[1] != q[1] && S.count(get({p[0], q[1]})) && S.count(get({q[0], p[1]})))
                    res = min(res, abs(p[0] - q[0]) * abs(p[1] - q[1]));
            }
        if (res == INT_MAX) res = 0;
        return res;
    }
};