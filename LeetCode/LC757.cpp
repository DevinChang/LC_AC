class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            if(a[1] != b[1]) return a[1] < b[1];
            return a[0] > b[0];
        });
        vector<int> q(1, -1);
        int cnt = 0;
        for(auto& r : intervals) {
            if(r[0] > q[cnt]) {
                q.push_back(r[1] - 1);
                q.push_back(r[1]);
                cnt += 2;
            } else if (r[0] > q[cnt-1]) {
                q.push_back(r[1]);
                cnt++;
            }
        }
        return cnt;
    }
};