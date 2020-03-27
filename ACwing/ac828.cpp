//
// Created by devinchang on 2020/3/13.
//

#include <bits/stdc++.h>
using namespace std;

/*模拟栈*/

const int N = 100010;

int stk[N];
int tt;

int m;


int main(){
    cin >> m;
    while(m--){
        string op;
        cin >> op;
        if(op == "push"){
            int x;
            cin >> x;
            stk[++tt] = x;
        }
        else if(op == "pop") tt--;
        else if(op == "empty"){
            cout << (tt ? "NO" : "YES") << endl;
        }
        else
            cout << stk[tt] << endl;
    }

    return 0;
}

