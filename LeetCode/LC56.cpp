#include "util.h"


vector<vector<int>> merge(vector<vector<int>> &intervals){
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    int st = -2e9, ed = -2e9;
    vector<int> tmp(2);
    for(auto seg : intervals){
        if(ed < seg[0]){
            if(st != -2e9) {
                tmp[0] = st,tmp[1] = ed;
                res.push_back(tmp);
            }
            st = seg[0], ed = seg[1];
        }
        else ed = max(ed, seg.second);
    }
    if(st != -2e9) {
        tmp[0] = st, tmp[1] = ed;
        res.push_back(tmp);
    }
    return res;
}