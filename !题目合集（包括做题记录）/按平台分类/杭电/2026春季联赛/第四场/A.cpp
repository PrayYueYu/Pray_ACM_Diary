#include<bits/stdc++.h>
#define int long long
const int N = 2e3 + 10, mod = 998244353, INF = 1e18;
int vis[N][N];
int n, m, a[N][N], f[N * 3];
int dx[10] = {0, 1, 1, 1, 0, 0, -1, -1, -1};
int dy[10] = {0, 1, 0, -1, 1, -1, 1, 0, -1};
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
inline bool bfs(int sx, int sy) {
	std::queue<std::pair<int, int>> q;
	q.push({sx, sy});
	int flag = false;
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		if(x == 1 || y == m) flag = true;
		q.pop();
		if(vis[x][y]) continue;
		vis[x][y] = true;
		for(int i = 1; i <= 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
			if(a[nx][ny] == a[sx][sy]) q.push({nx, ny});
		}
	}
	return flag;
}
void solve() {
	n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			a[i][j] = read();
			vis[i][j] = false;
		}
	}
	for(int i = 0; i <= n + m + 1; i++) f[i] = false;
	for(int i = 1; i <= n; i++) {
		if(bfs(i, 1)) f[a[i][1]] = true;
	}
	for(int i = 1; i <= m; i++) {
		if(bfs(n, i)) f[a[n][i]] = true;
	}
	for(int i = 0; i <= n + m + 1; i++) {
		if(!f[i]) {
			std::cout << i << '\n';
			return;
		}
	}
}
signed main() {
	int T = read();
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
