#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int ans, n, k, ne[N],to[N], fi[N], num;
int fa[N], d[N], vis[N];
void add(int u, int v) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
}
void dfs(int u, int faa) {
	d[u] = d[faa] + 1;
	fa[u] = faa;
	if(d[u] % k == 0) {
		vis[u] = true;
		if(u != 1) ans += k;
	}
	int flag = false;
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == faa) continue;
		dfs(v, u);
		flag = true;
	}
	if(!flag) {
		int now = u;
		while(true) {
			if(vis[now]) break;
			now = fa[now];
			ans++;
		}
	}
}
void solve() {
	std::cin >> n >> k;
	for(int i = 1; i < n; i++) {
		int u, v; std::cin >> u >> v;
		add(u, v); add(v, u);
	}
	d[0] = -1;
	dfs(1, 0);
	std::cout << ans;
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
