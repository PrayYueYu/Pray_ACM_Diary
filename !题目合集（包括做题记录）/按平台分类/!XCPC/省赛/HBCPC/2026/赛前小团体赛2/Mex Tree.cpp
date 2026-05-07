#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int ans[N], siz[N], minn[N], n, a[N];
int to[N], ne[N], fi[N], num;
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
	minn[u] = a[u];
	siz[u] = 1;
	int f = true, maxn = 0;
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == fa) continue;
		dfs(v, u);
		minn[u] = std::min(minn[u], minn[v]);
		siz[u] += siz[v];
		if(minn[v] < a[u]) {
			f = false;
		}
		maxn = std::max(maxn, siz[v]);
	}
	if(f) ans[a[u]] = n - siz[u];
	if(!a[u]) ans[a[u]] = maxn;
}
void solve() {
	n = read();
	int root = 0;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		if(!a[i]) root = i;
		ans[i] = 0;
	}
	for(int i = 2; i <= n; i++) {
		int u = read();
		add(u, i); add(i, u);
	}
	dfs(root, 0);
	for(int i = 0; i < n; i++) std::cout << ans[i] << ' ';
	std::cout << n;
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
