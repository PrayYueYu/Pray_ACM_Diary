#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, a[N], b[N], fa[N], f[N], vis[N];
std::priority_queue<std::pair<double, int>> q;
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
	for(int i = 0; i <= n + 1; i++) {
		a[i] = b[i] = fa[i] = f[i] = vis[i] = 0;
	}
}
double getdb(int x) {
	double now = (double)a[x] / (double)b[x];
	return now;
}
int getfa(int u) {
	if(fa[u] == u) return u;
	return fa[u] = getfa(fa[u]);
}
void merge(int u, int v) {
	u = getfa(u);
	if(u == v) return;
	fa[u] = v;
	a[v] += a[u];
	b[v] += b[u];
}
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= n; i++) b[i] = read();
	for(int i = 1; i <= n; i++) {
		f[i] = read();
		fa[i] = i;
		q.push({getdb(i), i});
	}
	int ans = 0;
	while(!q.empty()) {
		int u = q.top().second;
		double ft = q.top().first;
		q.pop();
		if(getdb(u) != ft || vis[u]) continue;
		vis[u] = true;
		int fav = getfa(f[u]);
		ans += a[u] * b[fav];
		merge(u, fav);
		if(fav) q.push({getdb(fav), fav});
	}
	std::cout << ans << '\n';
}
signed main() {
	int T = 1; 
	T = read();
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*
1
3
3 1 10
5 10 1
0 1 1
	Writer: ÔÂö§Þ±‹¬ 
*/
