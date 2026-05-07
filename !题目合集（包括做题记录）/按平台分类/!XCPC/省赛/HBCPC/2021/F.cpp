#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, m, k, num, vis[N], f, fa[N], ft;
int ne[N], to[N], fi[N], fx[N], fw[N];
double w[N], r[N];
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
bool check(int u, int v) {
	if(w[u] * r[u] + w[v] * r[v] != 0.0) return false;
	return true;
}
double calc(int u, int v) {
	double ans = -w[u] * r[u] / r[v];

	return ans;
}
void dfs(int u, int st) {
	if(fw[u]) ft = false;
	fa[u] = st;
	vis[u] = true;
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(fx[v]) {
			if(fx[v] + fx[u] != 0) {
				f = false;
				return;
			}
		}
		else fx[v] = -fx[u];
		if(vis[v]) continue;
		dfs(v, st);
	}
}
void solve() {
	f = true;
	n = read(), m = read(), k = read();
	for(int i = 1; i <= n; i++) r[i] = read();
	for(int i = 1; i <= m; i++) {
		int u = read(), v = read();
		add(u, v); add(v, u);
	}
	for(int i = 1; i <= k; i++) {
		int p = read(), x = read();
		w[p] = x; 
		fw[p] = true;
		if(x >= 0) fx[p] = 1;
		else fx[p] = -1;
	}
	for(int i = 1; i <= n; i++) {
		if(vis[i]) continue;
		if(fx[i] && w[i] != 0) {
			dfs(i, i);
		}
	}
	if(!f) {
		std::cout << "It is not steampunk!";
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(vis[i]) continue;
		f = true;
		ft = true;
		if(fx[i]) continue;
		fx[i] = 1;
		dfs(i, i);
		if(f && ft) {
			std::cout << "oo";
			return;
		}
	}
	f = true;
	for(int i = 1; i <= n; i++) {
		double wx = (double)fx[i] * fabs(w[fa[i]] * r[fa[i]] / r[i]);
		if(fw[i]) {
			if(wx != w[i]) f = false;
		}
		else w[i] = wx;
	}
	if(!f) std::cout << "It is not steampunk!";
	else {
		std::cout << "Steampunk!\n";
		double eps = 1e-10;
		for(int i = 1; i <= n; i++) {
			printf("%.4lf ", w[i] + eps);
		}
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
