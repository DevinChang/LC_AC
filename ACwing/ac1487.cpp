#include <iostream>
#include <algorithm>
using namespace std;


const int N = 100010, MOD = 1e9+7;

int dp[N];
int n1, n2, m;



int main(){
    scanf("%d%d%d", &n1, &n2, &m);

    dp[0] = 1;
    
    // 取普通币的情况类似于完全背包问题
    for(int i = 0; i < n1; i++){
        int p;
        scanf("%d", &p);
        for(int j = p; j <= m; j++) dp[j] = (dp[j] + dp[j-p]) % MOD;
    }

    // 取纪念币的情况类似于01背包
    for(int i = 0; i < n2; i++){
        int p;
        scanf("%d", &p);
        for(int j = m; j >= p; j--) dp[j] = dp[j] = (dp[j] + dp[j-p]) % MOD;
    }

    printf("%d\n", dp[m]);

    return 0;
}