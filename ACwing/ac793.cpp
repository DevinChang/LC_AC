//
// Created by devinchang on 2020/3/22.
//

#include <bits/stdc++.h>
using namespace std;


// 高精度乘法，a的长度较大，可以用字符串存储，而b的长度较小，直接用int存储


vector<int> mul(vector<int> &A, int b){
    vector<int> ret;
    int alen = A.size();
    for(int i = 0, t = 0; i < alen || t; i++){
        if(i < alen) t += A[i] * b;
        ret.push_back(t % 10);
        t /= 10;
    }
    return ret;
}



int main(){
    string a;
    int b;
    cin >> a >> b;
    vector<int> A;
    for(int i = a.size()-1; i >= 0; i--) A.push_back(a[i]-'0');

    vector<int> ret;
    ret = mul(A, b);

    for(int i = ret.size() - 1; i >= 0; i--) cout << ret[i];


    return 0;
}

