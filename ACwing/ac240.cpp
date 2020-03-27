#include <iostream>

using namespace std;


const int N = 1000010;

int p[N];
int d[N];


int find(int x){
    if(x != p[x]){
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}





int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) p[i] = i;

    int res = 0;

    while(k--){
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);
        if(x > n || y > n) res++;
        else{
            // px表示x的根节点，py表示y的根节点
            int px = find(x), py = find(y);
            // t == 1 表示x和y是同类.若x吃y或者y吃x则说明是谎言
            if(t == 1){
                if(px == py && (d[x] - d[y]) % 3) res++;
                else if(px != py){
                    p[px] = py;
                    d[px] = d[y] - d[x];
                }
            }
            else{
                // t == 2 表示 x吃y。若x吃y，则有(d[x]-d[y]) % 3 === 1
                if(px == py && (d[x] - d[y] - 1) % 3) res++;
                else if(px != py){
                    p[px] = py;
                    d[px] = d[y] - d[x] + 1;
                }
            }
        }
    }

    printf("%d\n", res);
    



    return 0;
}