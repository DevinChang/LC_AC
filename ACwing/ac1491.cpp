#include <iostream>
#include <algorithm>
using namespace std;


const int N = 20;
bool g[N][N];
bool st[N];
int pos[N];
int n, m;


// 枚举的是第u个位置应该填什么
int dfs(int u) {
	if(u == n) {
		// 如果最后一个位置和第一个位置是朋友关系，则不合法
		if(g[pos[n-1]][pos[0]]) return 0;
		return 1;
	}
	int res = 0;
	for(int i = 1; i <= n; i++) {
		if(!st[i] && !g[i][pos[u-1]]) {
			st[i] = true;
			pos[u] = i;
			res += dfs(u+1);
			st[i] = false;
		}
	}
	return res;
}


int main() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a][b] = g[b][a] = true;
	}
	pos[0] = 1;
	st[1] = true;
	cout << dfs(1) << endl;
	return 0;
}