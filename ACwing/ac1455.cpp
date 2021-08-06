#include <iostream>
using namespace std;

const int N = 1010;
int n, m;
int a[N];

/*
约瑟夫环公式：
f(N, M) = (f(N-1, M) + M) % M
->
f(i, M) = (f(i-1, a[(N-i) % M])) % M
*/


int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		for(int i = 0; i < m; i++) scanf("%d", &a[i]);

		int res = 0;
		for(int i = 2; i <= n; i++) {
			res = (res + a[(n - i) % m]) % i;
		}
		printf("%d\n", res);
	}
	return 0;
}