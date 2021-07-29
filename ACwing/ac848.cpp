#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;



int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n+10);
    vector<int> d(n+10);
    while(m--) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        d[y]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(d[i] == 0) q.push(i);
    }
    int cnt = 0;
    vector<int> res;
    while(q.size())  {
        auto t = q.front();
        cnt++;
        q.pop();
        res.push_back(t);
        for(auto x : g[t]) {
            if(--d[x] == 0) {
                q.push(x);
            }
        }
    }
    if(cnt != n) {
        puts("-1");
        return 0;
    }
    for(int i = 0; i < res.size(); i++) cout << res[i] << " ";
    return 0;
}