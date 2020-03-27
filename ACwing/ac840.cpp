#include <iostream>
#include <cstring>
using namespace std;




const int N = 100003;
const int M = 200003;

const int null = 0x3f3f3f3f;

int h[N], e[N], ne[N], idx;


void insert(int x){
    // 计算插入的位置
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}


bool find(int x){
    int k = (x % N + N) % N;
    for(int i = h[k]; i != -1; i = ne[i]){
        if(e[i] == x){
            return true;
        }
    }
    return false;
}

int find_kf(int x){
    int t = (x % M + M ) % M;
    while(h[t] != null && h[t] != x){
        t++;
        if(t == M) t = 0;
    }
    return t;
}



int main(){
    int n;
    scanf("%d", &n);
    
    /*

    memset(h, -1, sizeof h);

    while(n--){
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        if(*op == 'I') insert(x);
        else{
            if(find(x)) puts("Yes");
            else puts("No");
        }
    }
    */
   memset(h, 0x3f, sizeof h);
   while(n--){
       char op[2];
       int x;
       scanf("%s%d", op, &x);
       if(*op == 'I') h[find_kf(x)] = x;
       else{
           if(h[find_kf(x)] == null) puts("No");
           else puts("Yes");
       }
   }



    return 0;
}
