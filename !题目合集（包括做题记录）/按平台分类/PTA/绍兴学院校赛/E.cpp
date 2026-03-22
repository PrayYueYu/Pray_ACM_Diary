#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int ne[N], to[N], fi[N], num, ans[N];
int n, cnt[N], fac[N], f[N], a[N], b[N];
int read() {
	int x;
	std::cin >> x;
	return x;
}
void add(int u, int v) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
}
int ksm(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = (ans * x) % mod;
		x = (x * x) % mod;
		y >>= 1;
	}
	return ans;
}
int getf(int u) {
	int ans = 1;
	ans = fac[cnt[u] - 1] * ksm(a[u], mod - 2) % mod;
	ans = ans * b[u] % mod;
	return ans;
}
void dfs(int u, int fa) {
	cnt[u]++;
	a[u] = b[u] = 1;
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == fa) continue;
		dfs(v, u);
		cnt[u] += cnt[v];
		b[u] = (b[u] * f[v]) % mod;
		a[u] = (a[u] * fac[cnt[v]]) % mod;
	}
	f[u] = getf(u);
}
void getans(int u, int fa) {
	ans[u] = f[u];
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == fa) continue;
		int fv = f[v], fu = f[u];
		a[u] = a[u] * ksm(fac[cnt[v]], mod - 2) % mod;
		b[u] = b[u] * ksm(f[v], mod - 2) % mod;
		cnt[u] -= cnt[v];
		cnt[v] += cnt[u];
		f[u] = getf(u);
		a[v] = a[v] * fac[cnt[u]] % mod;
		b[v] = b[v] * f[u] % mod;
		f[v] = getf(v);
		getans(v, u);
		f[v] = fv;
		b[v] = b[v] * ksm(f[u], mod - 2) % mod;
		a[v] = a[v] * ksm(fac[cnt[u]], mod - 2) % mod;
		f[u] = fu;
		cnt[v] -= cnt[u];
		cnt[u] += cnt[v];
		b[u] = b[u] * f[v] % mod;
		a[u] = a[u] * fac[cnt[v]] % mod;
	}
}
void solve() {
	fac[0] = 1;
	n = read();
	for(int i = 1; i <= n + 2; i++) {
		fac[i] = fac[i - 1] * i;
		fac[i] %= mod;
	}
	for(int i = 1; i <= n - 1; i++) {
		int u = read(), v = read();
		add(u, v); add(v, u);
	}
	dfs(1, 0);
	getans(1, 0);
	for(int i = 1; i <= n; i++) {
		std::cout << ans[i] << '\n';
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
