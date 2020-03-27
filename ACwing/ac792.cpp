//
// Created by devinchang on 2020/3/22.
//

#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &A, vector<int> &B){
    int alen = A.size(), blen = B.size();
    if(alen != blen) return alen > blen;

    for(int i = alen-1; i >= 0; i--){
        if(A[i] != B[i]) return A[i] > B[i];
    }
    return true;
}


vector<int> sub(vector<int> &A, vector<int> &B){
    vector<int> ret;
    int alen = A.size(), blen = B.size();
    for(int i = 0, t = 0; i < alen; i++){
        t = A[i] - t;
        if(i < blen) t -= B[i];
        // 防止负数
        ret.push_back((t + 10) % 10);
        if(t < 0) t = 1;
        else t = 0;
    }

    // 清除多余的0
    while(ret.size() > 1 && ret.back() == 0) ret.pop_back();
    return ret;
}



int main(){
    string a,b;
    cin >> a >> b;
    vector<int> A, B;
    for(int i = a.size()-1; i >= 0; i--) A.push_back(a[i]-'0');
    for(int i = b.size()-1; i >= 0; i--) B.push_back(b[i]-'0');

    vector<int> ret;

    if(cmp(A, B)) ret = sub(A, B);
    else {
        cout << "-";
        ret = sub(B, A);
    }

    for(int i = ret.size()-1; i >= 0; i--) cout << ret[i];



    return 0;
}

