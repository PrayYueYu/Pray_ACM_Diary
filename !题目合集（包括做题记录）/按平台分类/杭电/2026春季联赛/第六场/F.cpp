#include<bits/stdc++.h>
#define int long long
const int N = 1e3 + 10, mod = 998244353, INF = 1e18;
int n, m, Q, vis[N][N];
std::vector<int> a[N][2];
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
void init() {
	for(int i = 1; i <= n; i++) {
		a[i][0].clear();
		a[i][1].clear();
	}
}
void solve() {
	n = read(), m = read(), Q = read();
	for(int i = 1; i <= m; i++) {
		int u = read(), v = read();
		char c; std::cin >> c;
		if(c == '(') {
			a[u][0].push_back(v);
			a[v][0].push_back(u);
		}
		else {
			a[u][1].push_back(v);
			a[v][1].push_back(u);
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			vis[i][j] = INF;
		}
	}
	std::priority_queue<std::pair<int, int>> q;
	for(int i = 1; i <= n; i++) {
		q.push({i, i});
		vis[i][i] = 0;
	}
	while(!q.empty()) {
		int x = q.top().first;
		int y = q.top().second;
		q.pop();
		for(int k = 1; k <= n; k++) {
			if(k == x || k == y) continue;
			if(vis[y][k] != INF) {
				if(vis[x][y] + vis[y][k] < vis[x][k]) {
					vis[x][k] = vis[x][y] + vis[y][k];
					q.push({x, k});
				}
			}
			if(vis[k][x] != INF) {
				if(vis[k][x] + vis[x][y] < vis[k][y]) {
					vis[k][y] = vis[k][x] + vis[x][y];
					q.push({k, y});
				}
			}
		}
		for(auto sx: a[x][0]) {
			for(auto sy: a[y][1]) {
				if(vis[sx][sy] > vis[x][y] + 2) {
					vis[sx][sy] = vis[x][y] + 2;
					q.push({sx, sy});
				}
			}
		}
	}
	for(int i = 1; i <= Q; i++) {
		int u = read(), v = read();
		if(vis[u][v] != INF) {
			std::cout << vis[u][v] << '\n';
		}
		else std::cout << -1 << '\n';
	}
}
signed main() {
	int T = 1;
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*

*/
