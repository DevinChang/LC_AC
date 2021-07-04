#include <iostream>
using namespace std;



const int N = 1010;
int n;
int arr[N], f[N];


int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);
    
    for(int i = 1; i <= n; i++) {
        f[i] = 1;
        for(int j = 1; j <= i; j++) {
            if(arr[j] < arr[i]) f[i] = max(f[i], f[j] +1);
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++) res = max(res, f[i]);
    
    cout << res << endl;
    return 0;
}