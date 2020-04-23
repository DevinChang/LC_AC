#include <iostream>
#include <algorithm>
using namespace std;


typedef long long LL;

const int N = 100010;

int h[N], l[N], r[N];
int st[N];



int main(){
    int n;
    while(scanf("%d", &n), n){
        for(int i = 1; i <= n; i++) scanf("%d", &h[i]);
        // 设置哨兵，防止越界
        h[0] = h[n+1] = -1;
        int tt = 0; // 栈顶
        st[tt] = 0;
        // 寻找左边界
        for(int i = 1; i <= n; i++){
            // 若是栈顶元素大于当前高度，则弹出栈
            while(h[st[tt]] >= h[i]) tt--;
            l[i] = st[tt];
            st[++tt] = i; // 入栈
        }

        tt = 0; // 重置栈顶，寻找右边界
        st[tt] = n+1;
        for(int i = n; i > 0; i--){
            while(h[st[tt]] >= h[i]) tt--;
            r[i] = st[tt];
            st[++tt] = i;
        }

        LL ans = 0;
        for(int i = 1; i <= n; i++){
            ans = max(ans, (LL)h[i] * (r[i] - l[i] - 1));
        }

        printf("%lld\n", ans);
    }


    return 0;
}