#include<bits/stdc++.h>
#define int long long
const int N = 10 + 10, mod = 998244353, INF = 1e18;
int n, m, a[N][N], vis[N * N], g[N][N];
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
	n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			a[i][j] = read();
			vis[a[i][j]] = true;
		}
	}
	for(int i = 1; i <= std::max(n, m); i++) {
		g[i][1] = g[1][i] = 1;
	}
	for(int i = 2; i <= n; i++) {
		for(int j = 2; j <= m; j++) {
			g[i][j] = g[i - 1][j] + g[i][j - 1];
		}
	}
	int ans = 0;
	for(int t = 1; t <= n * m; t++) {
		if(!vis[t]) continue;
		int now = 0;
		if(a[1][1] == t) {
			ans += g[n][m];
			continue;
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				if(a[i][j] == t) {
					now += g[i][j] * g[n - i + 1][m - j + 1];
				}
			}
		}
		ans += now;
	}
	std::cout << ans << '\n';
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			vis[a[i][j]] = false;
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
1
9 2
6 2
5 4
6 3
3 6
2 6
2 6
1 4
5 6
3 2
*/
