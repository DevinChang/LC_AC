#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

// 最大n是5000，2^12=4097, 即最大异或和的数是2^13 - 1
const int N = 5010, M = 8192, MOD = 1e9 + 7;

int n;
int a[N];
int f[2][M];

bool is_prime(int x)
{
    for (int i = 2; i * i <= x; i ++ )
        if (x % i == 0)
            return false;
    return true;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    f[0][0] = 1;
    for (int i = 1; i <= n; i ++ )
        for (int j = 0; j < M; j ++ )
        {
            f[i & 1][j] = f[i - 1 & 1][j];
            if ((j ^ a[i]) < M) f[i & 1][j] = (f[i & 1][j] + f[i - 1 & 1][j ^ a[i]]) % MOD;
        }

    int res = 0;
    for (int i = 2; i < M; i ++ )
        if (is_prime(i))
            res = (res + f[n & 1][i]) % MOD;

    cout << res << endl;

    return 0;
}