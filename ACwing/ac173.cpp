#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int,int> PII;

const int N = 1010;
char g[N][N];
int d[N][N];
int n, m;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void bfs() {
	memset(d, -1, sizeof d);
	queue<PII> q;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(g[i][j] == '1') {
				q.push({i,j});
				d[i][j] = 0;
			}
		}
	}
	while(q.size()) {
		auto t = q.front();
		q.pop();
		int x = t.first, y = t.second;
		for(int i = 0; i < 4; i++) {
			int a = x + dx[i], b = y + dy[i];
			if(a >= 0 && a < n && b >= 0 && b < m && d[a][b] == -1) {
				d[a][b] = d[x][y] + 1;
				q.push({a, b});
			}
		}
	}
}


int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> g[i];
	}
	bfs();
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) 
			printf("%d ", d[i][j]);
		puts("");
	}
	return 0;
}
