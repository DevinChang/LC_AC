//
// Created by devinchang on 2019/11/14.
//
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> ret;
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end());
    ret.push_back(intervals[0]);
    for(int i = 0; i < intervals.size(); i++){
        if(ret.back()[1] >= intervals[i][0]){
            ret.back()[1] = max(intervals[i][1], ret.back()[1]);
        }
        else
            ret.push_back(intervals[i]);
    }
    return ret;
}

vector<vector<int>> insert_bad(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> ret;
    int ileft = newInterval[0], iright = newInterval[1];
    int minleft = intervals[0][0], maxright = intervals[0][1];
    bool ismin = false, ismax = false;
    for (auto &val : intervals) {
        if (val[1] > ileft && !ismin) {
            minleft = val[0];
            ismin = true;
        }
        if (iright <= val[0] && !ismax) {
            if(iright == val[0])
                maxright = val[1];
            else
                maxright = iright;
            ismax = true;
        }
    }
    int i = 0;
    for (; i < intervals.size(); i++) {
        if (intervals[i][1] < minleft)
            ret.push_back(intervals[i]);
        if (intervals[i][0] > maxright)
            break;
    }
    vector<int> mergeval{minleft, maxright};
    ret.push_back(mergeval);
    for (int k = i; k < intervals.size(); k++) {
        ret.push_back(intervals[k]);
    }
    return ret;
}


void printResults(vector<vector<int>> &ret){
    for(auto r : ret){
        cout << r[0] << " " << r[1] << endl;
    }
}



int main(){
    vector<vector<int>> intervals{{1,2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<vector<int>> intervals2{{1, 5}};
    vector<vector<int>> intervals3{{1, 3}, {6, 9}};
    vector<int> newInterval{4, 8};
    vector<int> newInterval2{2, 3};
    vector<int> newInterval3{2, 5};
    auto ret = insert(intervals, newInterval);
    auto ret2 = insert(intervals2, newInterval2);
    auto ret3 = insert(intervals3, newInterval3);
    printResults(ret);
    printResults(ret2);
    printResults(ret3);
    return 0;
}

