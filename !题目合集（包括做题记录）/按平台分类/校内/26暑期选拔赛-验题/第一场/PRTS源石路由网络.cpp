#include<bits/stdc++.h>
const int N = 2e3 + 10, mod = 998244353, INF = 1e9;
int n, m, c[N], d[N], num;
std::vector<std::pair<int, int>> ed[N];
long long f[N][N];
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
	for(int i = 0; i <= n + 2; i++) {
		for(int j = 0; j <= m + 2; j++) {
			f[i][j] = 0;
		}
		ed[i].clear();
		d[i] = 0;
	}
}
inline void dfs(int u, int now) {
	int minn = std::min(c[u], d[u]);
	for(register int i = 0; i <= minn; i++) 
		f[u][i] = 1;
	for(auto x: ed[u]) {
		int v = x.first, w = x.second;
		d[v] = std::min(w, now);
		dfs(v, d[v]);
//		num++;
		for(register int i = d[u]; i >= 0; i--) {
			int sum = 0;
			minn = std::min({d[v], i});
			for(register int j = 0; j <= minn; j++) {
				long long t = f[u][i - j] * f[v][j] % mod;
				sum = (sum + t) % mod;
			}
			f[u][i] = sum;
		}
	}
}
void solve() {
	std::cin >> n >> m;
	for(int i = 1; i <= n; i++) std::cin >> c[i];
	for(int i = 1; i < n; i++) {
		int u, v, w;
		std::cin >> u >> v >> w;
		ed[u].push_back({v, w});
	}
	d[1] = m;
	dfs(1, m);
	std::cout << f[1][m] << '\n';
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0); 
	freopen("2.in", "r", stdin);
	int T; std::cin >> T;
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*

*/
