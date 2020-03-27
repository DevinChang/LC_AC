
#include <iostream>
#include <string>
using namespace std;


const int N = 100010;

int p[N];
int cnt[N]; // 保存每个集合的个数


int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}



int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i <= n; i++){
        p[i] = i;
        cnt[i] = 1;
    }

    while(m--){
        string op;
        int a, b;
        cin >> op;
        if(op[0] == 'C'){
            scanf("%d%d", &a, &b);
            a = find(a), b = find(b);
            if(a != b){
                p[a] = b;
                cnt[b] += cnt[a];
            }
        }
        else if(op == "Q1"){
            scanf("%d%d", &a, &b);
            if(find(a) == find(b)) puts("Yes");
            else puts("No");
        }
        else{
            scanf("%d", &a);
            printf("%d\n", cnt[a]);
        }
    }

    


    return 0;
}
