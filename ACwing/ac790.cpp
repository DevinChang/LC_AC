//
// Created by devinchang on 2020/3/22.
//

#include <bits/stdc++.h>
using namespace std;

// 浮点数二分
// 需要注意的是浮点的边界判断


int main(){

    double x;
    cin >> x;

    double l = -100, r = 100;
    while(r - l > 1e-8){
        double mid = (l + r) / 2;
        if(mid * mid * mid >= x) r = mid;
        else l = mid;
    }

    //cout << l << endl;
    printf("%.6lf", l);


    return 0;
}

