class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {
        vector<vector<int>> res;
        a.push_back(b);
        sort(a.begin(), a.end());
        int st = a[0][0], ed = a[0][1];
        for(int i = 1; i < a.size(); i++) {
            if(a[i][0] > ed) {
                res.push_back({st,ed});
                st = a[i][0], ed = a[i][1];
            } else {
                ed = max(ed, a[i][1]);
            }
        }
        res.push_back({st, ed});
        return res;
    }
};