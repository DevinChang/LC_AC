#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> PII;



int main() {
    vector<PII> range;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        range.push_back({l,r});
    }
    
    sort(range.begin(), range.end(), [&](PII a, PII b) {
        return a.second < b.second;
    });
    
    int res = 0, ed = -2e9;
    for(int i = 0; i < n; i++) {
        if(range[i].first > ed) {
            res++;
            ed = range[i].second;
        }
    }
    
    cout << res << endl;
    
    return 0;
}