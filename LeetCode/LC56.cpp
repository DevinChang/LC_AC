class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int st = intervals[0][0], ed = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] > ed) {
                res.push_back({st, ed});
                st = intervals[i][0];
                ed = intervals[i][1];
            }
            else ed = max(ed, intervals[i][1]);
        }
        res.push_back({st, ed});
        return res;
    }
};