//
// Created by devinchang on 2020/3/24.
//

//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int N = 100010;

int ihash[N];




int main(){
    string s;
    cin >> s;
    int n = s.size();
    int ans = 1;
    for(int i = 0, j = 0; i < n; i++){
        ihash[s[i]-'0']++;
        while(j < i && ihash[s[i]-'0'] > 1) ihash[s[j++]-'0']--;
        ans = max(ans, i - j + 1);
    }

    printf("%d\n", ans);


    return 0;
}

