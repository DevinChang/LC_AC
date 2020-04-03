#include <iostream>
#include <algorithm>

using namespace std;


/*
股票买卖3：只允许进行两次交易
*/


const int N = 100010;
int p[N];
int f[N], b[N]; 

int n;

int maxProfit(int p[]){
    if(n < 1) return 0;
    int minprice = p[0];
    for(int i = 1; i < n; i++){
        // f[i]表示第i天售出时的最大利润，要求前几天以最小价格买入
        f[i] = max(f[i-1], p[i]-minprice);
        minprice = min(minprice, p[i]);
    }
    int maxprice = p[n-1];
    for(int i = n-1; i >= 0; i--){
        // b[i]表示第i天售出时的最大利润，从后往前
        b[i] = max(b[i+1], maxprice - p[i]);
        maxprice = max(maxprice, p[i]);
    }

    int ans = 0;
    for(int i = 1; i < n; i++){
        ans = max(ans, f[i]+b[i]);
    }
    return ans;
}



int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &p[i]);

    int ans = maxProfit(p);

    printf("%d\n", ans);


    return 0;
}