#include <iostream>
#include <algorithm>
using namespace std;


/*
均分纸牌问题
思路：初看问题没有一点思路。可以抽象成一个代数问题。
设每堆牌分别为a1,a2,a3,...,an-1,an，牌的平均数为avg
每次转移的关系为x1,x2,x3,...,xn-1
可以列出下列关系
a1 - x1 = avg                        x1 = a1 - avg
a2 - x2 + x1 = avg                   x2 = a2 - avg + x1
a3 - x3 + x2 = avg          --->     x3 = a3 - avg + x2
...                                  ...
an-1 - xn-1 + xn-2 = avg             xn-1 = an-1 - avg + xn-2
an + xn-1 = avg                     
根据线性方程组的关系，可知上述方程存在唯一解
下面的问题就是，什么时候是一个合法的转移？可以观察到，xi是个定值，即每次转移的数值是固定的
故当xi>0时，表示至少转移一次，所以可以假设后面an-1的转移是可以正常发生的，使得每次转移都
不会出现不够的情况，之后再看看前面一堆是否成立，整个过程类似于数学归纳法，先假设后面的成立，
再证明加上前面那一个后是否成立。故有关系
x1 = 0, 成立
x1 > 0, 即a1 = avg + x1, 这种情况是一定可以转移的
x1 < 0, 表明这个时候是从a2转移到a1的，故需要先操作a2-an,之后再操作a1
*/

const int N = 110;
int arr[N];
int n;




int main(){
    scanf("%d", &n);
    int sum = 0, ans = 0;
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]), sum += arr[i];

    int avg = sum / n;
    int x = 0;
    for(int i = 0; i < n; i++){
        x = arr[i] - avg + x;
        if(x) ans++; // x > 0，表明一定可以转移
    }
    printf("%d\n", ans);
}
