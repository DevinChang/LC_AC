#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;

vector<PII> seg;

int n ;

int mergeSeg(){
    int len = seg.size();
    int st = -2e9, ed = -2e9;
    vector<PII> res;
    for(int i = 0; i < len; i++){
        if(ed < seg[i].first){
            if(st != -2e9) res.push_back({st, ed});
            st = seg[i].first;
            ed = seg[i].second;
        }
        else ed = max(ed, seg[i].second);
    }
    if(st != -2e9) res.push_back({st, ed});
    return res.size();
}


int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int l, r;
        scanf("%d%d", &l, &r);
        seg.push_back({l, r});
    }

    int ans = mergeSeg();

    printf("%d\n", ans);



    return 0;
}