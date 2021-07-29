#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=100010,M=200010;
int n,m;
int h[N],e[M],ne[M],idx;
int color[N];
void add(int a,int b){  //邻接表 
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
} 
bool dfs(int u,int c){   
    color[u]=c;   //把当前的点染成c 
    for(int i=h[u];i!=-1;i=ne[i]){
        int j=e[i];
        if(!color[j]){ //如果当前点没有被染过，换另一个颜色 染色 
            if(!dfs(j,3-c)) return 0;  //如果j染色出现矛盾，那就返回0 
        }                             //3-c就是换个颜色染色，就是1和2两种颜色 
        else if(color[j]==c) return 0; //相邻的点颜色一样 
    }
    return 1;
}

int main(){
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof(h));
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b),add(b,a);  //无向图 
    }
    bool flag=1; 
    for(int i=1;i<=n;i++){
        if(!color[i]){  //当前点如果没被染色 
            if(!dfs(i,1)){ //当有一个点染色出现矛盾，那就不是二分图 
                flag=false; 
                break;
            }
        }
    }
    if(flag) puts("Yes");
    else puts("No");
    return 0;
}

