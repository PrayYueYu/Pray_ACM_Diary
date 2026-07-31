#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, ne[N], fi[N], to[N], num, w[N], W;
int ans[N], fx[N], pre[N];
std::vector<std::vector<int>> f;
void init() {
	f.clear();
	for(int i = 0; i <= num + 2; i++) {
		ne[i] = to[i] = w[i] = 0;
	}
	num = 0;
	for(int i = 0; i <= n + 2; i++) {
		ans[i] = fi[i] = 0; 
	}
}
void add(int u, int v, int c) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
	w[num] = c;
}
void dfs(int u, int fa) {
	int flag = false;
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i], c = w[i];
		if(v == fa) continue;
		dfs(v, u);
		flag = true;
		for(int j = 0; j <= 2 * W; j++) {
			fx[j] = INF;
			pre[j] = 0;
		}
		for(int j = 0; j <= 2 * W; j++) {
			if(f[v][j] == INF) continue;
			if(j + c <= 2 * W) {
				if(f[v][j] - j - c >= 0) {
					fx[j + c] = std::min(fx[j + c], f[v][j]);
				}
				else fx[j + c] = std::min(fx[j + c], j + c);
			}
			if(j - c < 0) {
				fx[0] = std::min(fx[0], f[v][j] - j + c);
			}
			else fx[j - c] = std::min(fx[j - c], f[v][j]);
		}
		for(int j = 0; j <= 2 * W; j++) {
			if(j) pre[j] = std::max(pre[j - 1], j - fx[j]);
			else pre[j] = j - fx[j];
			if(f[u][j] == INF) f[u][j] = j - pre[j];
			else f[u][j] = std::max(f[u][j], j - pre[j]);
		}
	}
	if(!flag) f[u][0] = 0;
}
void solve() {
	std::cin >> n; W = -INF;
	for(int i = 1; i < n; i++) {
		int u, v, c;
		std::cin >> u >> v >> c;
		add(u, v, c); add(v, u, c);
		W = std::max(W, c);
	}
	f.resize(n + 2, std::vector<int>(2 * W + 2));
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= 2 * W; j++) {
			f[i][j] = INF;
		}
	}
	dfs(1, 0);
	for(int i = 1; i <= n; i++) {
		int ans = INF;
		for(int j = 0; j <= 2 * W; j++) {
			ans = std::min(ans, f[i][j]);
		}
		std::cout << ans << ' ';
	}
	std::cout << '\n';
}
signed main() {
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*
	Writer: ÔÂö§Þ±‹¬ 
*/
