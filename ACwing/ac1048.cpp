#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110;
// f[i][j]表示第i层用j个鸡蛋测量最坏情况的最小值
int f[N][N];
int n, m;


int main() {
    while(cin >> n >> m) {
        for(int i = 1; i <= n; i++) f[i][1] = i;
        for(int i = 1; i <= m; i++) f[1][i] = 1; 
        for(int i = 2; i <= n; i++) {
            for(int j = 2; j <= m; j++) {
                f[i][j] = f[i][j-1]; // 第j个鸡蛋没碎，等价于f[i][j-1]的方案
                // 找出在第几层碎的
                for(int k = 1; k <= i; k++) {
                    f[i][j] = min(f[i][j], max(f[k-1][j-1], f[i-k][j]) + 1);
                }
            }
        }
        cout << f[n][m] << endl;
    }
    return 0;
}
