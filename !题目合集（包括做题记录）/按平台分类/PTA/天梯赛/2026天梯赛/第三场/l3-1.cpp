#include<bits/stdc++.h>
#define int long long
const int N = 1e3 + 10, mod = 998244353, INF = 1e18;
int n, m, q, f[N][N], a[N];
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
void solve() {
	n = read(), m = read(), q = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j) f[i][j] = 0;
			else f[i][j] = INF;
		}
	}
	for(int i = 1; i <= m; i++) {
		int u = read(), v = read(), d = read();
		f[u][v] = f[v][u] = std::min(f[u][v], d);
	}
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				f[i][j] = std::min(f[i][j], f[i][k] + f[k][j] + a[k]);
			}
		}
	}
	for(int i = 1; i <= q; i++) {
		int u = read(), v = read();
		if(f[u][v] == INF) std::cout << -1 << '\n';
		else std::cout << f[u][v] << '\n';
	}
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T = 1;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
