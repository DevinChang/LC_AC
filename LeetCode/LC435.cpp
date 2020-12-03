class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n < 1) return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int>a, vector<int> b) {
            return a[1] < b[1];
        });
        int res = 1, t = intervals[0][1];
        for(int i = 1; i < n; i++){
            if(intervals[i][0] >= t){
                res++;
                t = intervals[i][1];
            }
        }
        return n - res;
    }
};