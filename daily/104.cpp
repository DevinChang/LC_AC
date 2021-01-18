#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;


int a[N];
int n;



int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    int res = 0;
    for(int i = 0; i < n; i++) res += abs(a[i] - a[n / 2]);
    cout << res; 
    return 0;
}