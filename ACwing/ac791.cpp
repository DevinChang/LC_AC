//
// Created by devinchang on 2020/3/22.
//

#include <bits/stdc++.h>
using namespace std;

/* 高精度加法
 * 主要是用数组模拟加法运算，还会涉及到压位运算的技巧
*/

// 压9位做法
const int base = 1000000000;


vector<int> add9(vector<int> &A, vector<int> &B){
    int alen = A.size(), blen = B.size();
    if(alen < blen) return add9(B, A);
    vector<int> ret;
    int t = 0;
    for(int i = 0; i < alen; i++){
        t += A[i];
        if(i < blen) t += B[i];
        ret.push_back(t % base);
        t /= base;
    }
    if(t) ret.push_back(t);
    return ret;
}


vector<int> add(vector<int> &A, vector<int> &B){
    int alen = A.size(), blen = B.size();
    if(alen < blen) return add(B, A);
    vector<int> ret;
    int t = 0;
    for(int i = 0;  i < alen; i++){
        t += A[i];
        if(i < blen) t += B[i];
        ret.push_back(t % 10);
        t /= 10;
    }
    if(t) ret.push_back(t);
    return ret;
}


int main(){
    string a, b;
    cin >> a >> b;
    vector<int> A, B;
    /*
    for(int i = a.size()-1; i >= 0; i--) A.push_back(a[i]-'0');
    for(int i = b.size()-1; i >= 0; i--) B.push_back(b[i]-'0');
    auto ret = add(A, B);

    for(int i = ret.size()-1; i >= 0; i--) cout << ret[i];
    */

    // 压九位做法

    for (int i = a.size() - 1, s = 0, j = 0, t = 1; i >= 0; i -- )
    {
        s += (a[i] - '0') * t;
        j ++, t *= 10;
        if (j == 9 || i == 0)
        {
            A.push_back(s);
            s = j = 0;
            t = 1;
        }
    }
    for (int i = b.size() - 1, s = 0, j = 0, t = 1; i >= 0; i -- )
    {
        s += (b[i] - '0') * t;
        j ++, t *= 10;
        if (j == 9 || i == 0)
        {
            B.push_back(s);
            s = j = 0;
            t = 1;
        }
    }

    auto C = add9(A, B);

    cout << C.back();
    for (int i = C.size() - 2; i >= 0; i -- ) printf("%09d", C[i]);
    cout << endl;


    return 0;
}

