#include<bits/stdc++.h>
#define int long long
#define time tm
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, m, ne[N], to[N], fi[N], num, vis[N], fa[N], d[N];
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
void add(int u, int v) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
}
void dfs(int u, int fa) {
	d[u] = d[fa] + 1;
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == fa) continue;
		dfs(v, u);
	}
}

void solve() {
	n = read(), m = read();
	int s = 0;
	for(int i = 1; i <= n; i++) {
		int f = read();
		if(f == -1) {
			f = 0, s = i;
			fa[i] = f;
			continue;
		}
		fa[i] = f;
		add(i, f); add(f, i);
	}
	vis[s] = true;
	d[0] = -1;
	dfs(s, 0);
	int sum = 0, maxn = -INF, ans = 0;
	for(int i = 1; i <= m; i++) {
		int x = read();
		if(vis[x]) {
			std::cout << ans << '\n';
			continue;
		}
		maxn = std::max(maxn, d[x]);
		while(true) {
			if(vis[x]) break;
			sum++;
			vis[x] = true;
			x = fa[x];
		}
		ans = sum * 2 - maxn;
		std::cout << ans << '\n';
	}
}
signed main() {
	int T = 1;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
