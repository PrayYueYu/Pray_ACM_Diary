#include<bits/stdc++.h>
const int N = 2e6 + 10, mod = 998244353;
int n, m, k, q, cnt, r[N], val;
int fi[N], to[N], ne[N], num;
int dx[10] = {0, 0, 0, 1, -1};
int dy[10] = {0, 1, -1, 0, 0};
std::vector<std::vector<int>> vis, a, f;
void init() {
	vis.clear();
	f.clear();
	a.clear();
	for(int i = 0; i <= num + 1; i++) {
		ne[i] = to[i] = 0;
	}num = 0;
	for(int i = 0; i <= cnt + 1; i++) {
		r[i] = fi[i] = 0;
	}
	cnt = 0; val = 0;
}
void dfs1(int x, int y) {
	std::queue<std::pair<int, int>> qu;
	qu.push({x, y});
	vis[x][y] = cnt;
	while(!qu.empty()) {
		int nx = qu.front().first;
		int ny = qu.front().second;
		qu.pop();
		for(int i = 1; i <= 4; i++) {
			int sx = nx + dx[i];
			int sy = ny + dy[i];
			if(!sx || !sy || sx > n || sy > m) continue;
			if(vis[sx][sy] || a[sx][sy]) continue;
			vis[sx][sy] = cnt;
			qu.push({sx, sy});
		}
	}
}
void dfs2(int u, int S) {
	f[r[S]][r[u]] = true;
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(f[r[S]][r[v]]) continue;
		dfs2(v, S);
	}
}
void add(int u, int v) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
}
void solve() {
	std::cin >> n >> m >> k >> q;
	a.resize(n + 2, std::vector<int>(m + 2));
	vis.resize(n + 2, std::vector<int>(m + 2));
	for(int i = 1; i <= n; i++) {
		std::string s;
		std::cin >> s;
		for(int j = 0; j < m; j++) {
			if(s[j] == '.') a[i][j + 1] = 0;
			else a[i][j + 1] = 1;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(!vis[i][j] && !a[i][j]) {
				cnt++;
				dfs1(i, j);
			}
		}
	}
	for(int i = 1; i <= k; i++) {
		int x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		if(vis[x1][y1] == vis[x2][y2]) continue;
		add(vis[x1][y1], vis[x2][y2]);
		if(!r[vis[x1][y1]]) r[vis[x1][y1]] = ++val;
		if(!r[vis[x2][y2]]) r[vis[x2][y2]] = ++val;
	}
	f.resize(val + 2, std::vector<int>(val + 2));
	for(int i = 1; i <= cnt; i++) {
		if(r[i]) dfs2(i, i);
	}
	for(int i = 1; i <= q; i++) {
		int x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		if(vis[x1][y1] == vis[x2][y2]) {
			std::cout << "1\n";
			continue;
		}
		if(!r[vis[x1][y1]] || !r[vis[x2][y2]]) {
			std::cout << "0\n";
			continue;
		}
		if(f[r[vis[x1][y1]]][r[vis[x2][y2]]]) {
			std::cout << "1\n";
		}
		else std::cout << "0\n";
	}
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*
----------------------
	Writer: ÔÂö§Þ±‹¬ | 
----------------------
*/
