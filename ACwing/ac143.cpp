#include<iostream>
#include<algorithm>

using namespace std;


const int N = 100010;
const int M = N * 31;

int son[M][2];
int idx;
int n;
int arr[N];


void insert(int x){
    int p = 0;
    for(int i = 30; i >= 0; i--){
        int &s = son[p][x >> i & 1];
        if(!s) s = ++idx;
        p = s;
    }
}

int search(int x){
    int p = 0;
    int res = 0;
    for(int i = 30; i >= 0; i--){
        int u = x >> i & 1;
        if(!son[p][!u]) {
            p = son[p][u];
            res = res *2 + u;
        }
        else{
            p = son[p][!u];
            res = res * 2 + !u;
        }
    }
    res = res ^ x;
    return res;
}







int main(){
    scanf("%d", &n);
    int res = 0;
    for(int i = 0;i < n; i++) {
        scanf("%d", &arr[i]);
        insert(arr[i]);
        res = max(res, search(arr[i]));
        
    }
    printf("%d\n", res);

    


    return 0;
}
