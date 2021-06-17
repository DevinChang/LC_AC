#include <iostream>
#include <algorithm>
using namespace std;



const int N = 1010;
int n, m;
int v[N], w[N], f[N];


int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];

	for(int i = 1; i <= n; i++) {
		for(int j = v[i]; j <= m; j++)
			f[j] = max(f[j], f[j-v[i]] + w[i]);
	}
	cout << f[m] << endl;
	return 0;
}