const int mod = 1e9 + 7, N = 100010;
int f[N][2][3];
class Solution {
public:
    int checkRecord(int n) {
        memset(f, 0, sizeof f);
        f[0][0][0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 2; j++) {
                for (int k = 0; k < 3; k++) {
                    if(!j) f[i+1][j+1][0] = (f[i+1][j+1][0] + f[i][j][k]) % mod;
                    if(k + 1 <= 2) f[i+1][j][k+1] = (f[i+1][j][k+1] + f[i][j][k]) % mod;
                    f[i+1][j][0] = (f[i+1][j][0] + f[i][j][k]) % mod;
                }
            }
        }
        int res = 0;
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 3; k++) 
                res = (res + f[n][j][k]) % mod;
        }
        return res;
    }
};