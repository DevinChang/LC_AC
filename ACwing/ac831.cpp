//
// Created by devinchang on 2020/3/15.
//

#include <bits/stdc++.h>
using namespace std;


/* 字符串KMP匹配 */

const int N = 10010;
const int M = 100010;

int n, m;
char s[M], p[N];
int ne[N];




int main(){
    /*
    cin >> n >> p+1 >> m >> s+1;

    // 求next数组
    for(int i = 2, j = 0; i <= n; i++){
        while(j && p[i] != p[j+1]) j = ne[j];
        if(p[i] == p[j+1]) j++;
        ne[i] = j;
    }

    for(int i = 1, j = 0; i <= m; i ++){
        while(j && s[i] != p[j+1]) j = ne[j];
        if(s[i] == p[j+1]) j++;
        if(j == n){
            // 匹配成功
            printf("%d ", i - n);
            j = ne[j];
        }

    }
     */

    cin >> n >> p >> m >> s;

    ne[0] = -1;

    for (int i = 1, j = -1; i < n; i ++ )
    {
        while (j >= 0 && p[j + 1] != p[i]) j = ne[j];
        if (p[j + 1] == p[i]) j ++ ;
        ne[i] = j;
    }

    for (int i = 0, j = -1; i < m; i ++ )
    {
        while (j != -1 && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j ++ ;
        if (j == n - 1) cout << i - j << ' ';
    }

    return 0;
}

