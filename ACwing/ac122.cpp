#include <iostream>
#include <algorithm>
using namespace std;


/*
糖果传递
这与纸牌传递类似，只不过是首尾相连。
设每个小朋友分别有糖果为a1,a2,a3,...,an-1,an，糖的平均数为avg
每次转移的关系为x1,x2,x3,...,xn-1,xn
可以列出下列关系
a1 - x1 + xn = avg                   x1 = a1 - avg + xn
a2 - x2 + x1 = avg                   x2 = a2 - avg + x1
a3 - x3 + x2 = avg          --->     x3 = a3 - avg + x2
...                                  ...
an-1 - xn-1 + xn-2 = avg             xn-1 = an-1 - avg + xn-2
an - xn + xn-1 = avg                 xn = an -avg + xn-1    
因为上述方程中存在多余的方程，故可以表示成选取某个变量的表达式，不妨选择为x1
x1 = x1
x2 = x1 + a2 - avg
x3 = a3 - avg + x2 = x1 + a2 + a3 - 2avg
...
xn-1 = x1 + a2 + ... + an-1 - (n-2)avg
xn = x1 + a2 + ... + an - (n-1)avg
进一步转换为
x1 = x1 - 0
x2 = x1 - (avg - a2)
x3 = x1 - (2avg - a2 - a3)
...
xn = x1 - ((n-1)avg - a2 - a3 - ... - an)
因为avg和ai都是定值，故可用Ci代替
x1 = x1 - c1
x2 = x1 - c2
...
xn = x1 - cn
题目求的是使所有人获得均等糖果的最小代价，即求的是
min{|x1|+|x2|+...+|xn|}
代入后得
min{|x1-c1| + |x2-c2| + ... + |xn-cn|}
这就转换成了货物选址的问题
*/

typedef long long LL;

const int N = 10000010;

LL s[N]; // 前缀和数组，用来优化求解式子中的球和
LL c[N];

int n;


int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%lld", &s[i]);
        s[i] += s[i-1];
    }

    LL avg = s[n] / n;

    for(int i = 2; i <= n; i++){
        c[i] = (i-1) * avg - (s[i]-s[1]);
    }

    sort(c+1, c + n + 1);

    LL mid = c[(n+1)/2]; // 若下标从1开始，则中位数的小标是n+1/2

    LL ans = 0;

    for(int i = 1; i <= n; i++){
        ans += abs(c[i] - mid) ;
    }

    printf("%lld", ans);
    
    return 0;

}
