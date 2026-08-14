#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int num, fi[N], ne[N], to[N], w[N];
int n, m, k, fa[N], vis[N], ans[N], cnt[N], f[N], r[N];
void init() {
	for(int i = 0; i <= num + 1; i++) {
		ne[i] = to[i] = w[i] = 0;
	} num = 0;
	for(int i = 0; i <= n + 1; i++) {
		fi[i] = vis[i] = ans[i] = fa[i] = cnt[i] = f[i] = r[i] = 0;
	}
	k = 0;
}
int getfa(int x) {
	if(fa[x] == x) return fa[x];
	return fa[x] = getfa(fa[x]);
}
void dfs1(int u, int F) {
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == F) continue;
		if(vis[v]) continue;
		ans[v] = w[i] - ans[u];
		vis[v] = true;
		dfs1(v, u);
	}
}
void dfs2(int u, int F, int x) {
	vis[u] = true;
	if(f[u]) ans[u] = r[u] - x;
	else ans[u] = r[u] + x;
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == F) continue;
		if(vis[v]) continue;
		dfs2(v, u, x);
	}
}
void dfs3(int u, int F, int c) {
	f[u] = f[F] ^ 1;
	r[u] = c - r[F];
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == F) continue;
		dfs3(v, u, w[i]);
	}
}
void add(int u, int v, int c) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
	w[num] = c;
}
void merge(int u, int v, int c) {
	int fau = getfa(u), fav = getfa(v);
	if(fau == fav) return;
	if(cnt[fau] > cnt[fav]) {
		std::swap(fau, fav);
		std::swap(u, v);
	}
	fa[fau] = fav;
	cnt[fav] += cnt[fau];
	add(u, v, c); add(v, u, c);
	if(!vis[u] && !vis[v]) dfs3(u, v, c);
}
void Print(int x) {
	if(x) {
		std::cout << "Yes\n";
		k++;
	}
	else std::cout << "No\n";
}
void solve() {
	std::cin >> n >> m;
	init();
	for(int i = 1; i <= n; i++) {
		fa[i] = i;
		cnt[i] = 1;
	}
	for(int i = 1; i <= m; i++) {
		int u, v, c; std::cin >> u >> v >> c;
		u = (u + k - 1) % n + 1;
		v = (v + k - 1) % n + 1;
		c = 2ll * ((c + k) % 1000000000 + 1);
		if(vis[u] < vis[v]) std::swap(u, v);
		if(getfa(u) != getfa(v)) {
			if(vis[u] && vis[v]) {
				if(ans[u] + ans[v] == c) {
					Print(true);
					merge(u, v, c);
				}
				else Print(false);
			}
			else if(vis[u] && !vis[v]) {
				merge(u, v, c);
				dfs1(u, 0);
				Print(true);
			}
			else {
				merge(u, v, c);
				Print(true);
			}
		}
		else {
			if(vis[u] && vis[v]) {
				if(ans[u] + ans[v] == c) Print(true);
				else Print(false);
			}
			else {
				if(f[u] != f[v]) {
					if(r[u] + r[v] == c) Print(true);
					else Print(false);
				}
				else {
					int x = 0;
					if(!f[u]) x = (c - r[u] - r[v]) / 2;
					else x = (r[u] + r[v] - c) / 2;
					dfs2(u, 0, x);
					Print(true);
				}
			}
		}
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
	}
	return 0;
}
/*
----------------------
	Writer: ÔÂö§Þ±‹¬ | 
----------------------
*/
