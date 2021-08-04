#include <iostream>
using namespace std;


const int N = 110;
int arr[N][N];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int n, m;


int main() {
    cin >> n >> m;
    
    for(int i = 1, x = 0, y = 0, d = 0; i <= n * m; i++) {
        arr[x][y] = i;
        int a = x + dx[d], b = y + dy[d];
        if(a < 0 || a >= n || b < 0 || b >= m || arr[a][b]) {
            d = (d + 1) % 4;
            a = x + dx[d], b = y + dy[d];
        }
        x = a, y = b;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cout << arr[i][j] << " ";
        cout << endl;
    }
    return 0;
}