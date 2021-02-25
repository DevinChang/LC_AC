class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int res = INT_MAX;
        vector<int> q;
        for(auto &t : timePoints) {
            int h, m;
            sscanf(t.c_str(), "%d:%d", &h, &m);
            q.push_back(60 * h + m);
        }
        sort(q.begin(), q.end());
        for(int i = 1; i < q.size(); i++) res = min(res, q[i] - q[i-1]);
        // 最后一个时刻和第一个时刻的间隔
        res = min(res, 24 * 60 + q[0] - q.back());
        return res;
    }
};