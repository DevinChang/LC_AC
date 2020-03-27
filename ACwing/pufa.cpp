//
// Created by devinchang on 2020/3/22.
//

#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int son[N][26];
int cnt[N];
int idx;
char str[N];
int n;


void insert(char str[]){
    int p = 0;
    for(int i = 0;str[i]; i++){
        int u = str[i] - 'a';
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

bool startwith(char prefix[], int p){
    for(int i = 0; str[i]; i++){
        int u = str[i] - 'a';
        if(!son[p][u]) return false;
        p = son[p][u];
    }
    return true;
}


void query(char str[]){
    int p = 0;
    for(int i = 0; str[i]; i++){
        int u = str[i] - 'a';
        if(!son[p][u]) return;
        p = son[p][u];
    }
}






int main(){
    char pre[N];
    scanf("%s", pre);
    insert(pre);
    //int p = pre[0] - 'a';
    scanf("%d", &n);

    while(n--){
        scanf("%s", str);
        insert(str);
        int p = str[0] - 'a';
        if(startwith(pre, p)){
            printf("%s\n", str);
        }
    }

    //query(pre);



    return 0;
}

