#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;
int dp[N][N];
int n, m;



int main(){
    scanf("%d%d", &n, &m);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int t;
            scanf("%d", &t);
            if(t != 0){
                dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }
    printf("%d\n", ans * ans);
    return 0;
}