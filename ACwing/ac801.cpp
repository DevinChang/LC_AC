#include <iostream>
using namespace std;

int lowbit(int x) {
	int res = 0;
	for(int i = x; i; i = i&(i-1)) res++;
	return res;
}

int main() {
	int n;
	scanf("%d", &n);
	while(n--) {
		int x, s;
		scanf("%d", &x);
		printf("%d ", lowbit(x));
	}
	return 0;
}