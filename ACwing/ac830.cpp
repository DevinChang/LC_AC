//
// Created by devinchang on 2020/3/13.
//

#include <bits/stdc++.h>
using namespace std;


/* 单调队列 */

const int N = 100010;

int stk[N];
int tt;


int n;



int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        while(tt && stk[tt] >= x) tt--;
        if(!tt) cout << -1 << " ";
        else cout << stk[tt] << " ";
        stk[++tt] = x;
    }

    return 0;
}

