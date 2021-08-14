#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


const int N = 100010;
int a[N], f[N], g[N];
int n;


int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);

	// 预处理f[i], g[i]
	// f[i]表示以i结尾的最大上升子串的长度
	for(int i = 1; i <= n; i++) {
		if(a[i-1] < a[i]) f[i] = f[i-1] + 1;
		else f[i] = 1;	
	}
	// g[i]表示s以i开头的最大上升子串的长度
	for(int i = n; i >= 0; i--) {
		if(a[i] < a[i+1]) g[i] = g[i+1] + 1;
		else g[i] = 1;
	}

	int res = 0;
	// 枚举删除的点
	for(int i = 1; i <= n; i++) {
		// 左边大于右边端点，不能拼接，求两边的最大值
		if(a[i-1] >= a[i+1]) res = max(res, max(f[i-1], g[i+1]));
		else res = max(res, f[i-1] + g[i+1]);
	}
	
	printf("%d\n", res);

	return 0;
}