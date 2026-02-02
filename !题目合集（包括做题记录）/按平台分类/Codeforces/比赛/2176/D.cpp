#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
using namespace std;
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int n, m, a[N];
int ne[N], to[N], fi[N], num, ux[N], vx[N];
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
map<int, int> f[N][2];
set<int> p[N];
void add(int u, int v) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
}
void init() {
	for(int i = 0; i <= n + 2; i++) {
		fi[i] = 0;
		f[i][0].clear();
		f[i][1].clear();
		p[i].clear();
	}
	for(int i = 0; i <= num + 2; i++) {
		ne[i] = to[i] = 0;
	}
	num = 0;
}
void solve() {
	n = read(), m = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= m; i++) {
		ux[i] = read(), vx[i] = read();
		f[vx[i]][0][a[ux[i]]]++;
		p[vx[i]].insert(a[ux[i]]);
	}
	for(int i = 1; i <= m; i++) {
		if(p[ux[i]].find(a[vx[i]] - a[ux[i]]) == p[ux[i]].end()) continue;
		add(ux[i], vx[i]);
	}
	int ans = m;
	for(int t = 3; t <= 88; t++) {
		int p1 = t % 2; int p2 = p1 ^ 1;
		for(int u = 1; u <= n; u++) {
			for(int i = fi[u]; i; i = ne[i]) {
				int v = to[i];
				f[v][p1][a[u]] += f[u][p2][a[v] - a[u]];
				f[v][p1][a[u]] %= mod;
			}
		}
		for(int u = 1; u <= n; u++) {
			for(auto x: p[u]) {
				f[u][p2][x] = 0;
				ans += f[u][p1][x]; ans %= mod;
			}
		}
	}
	cout << ans << '\n';
}
signed main() {
	int T = read();
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*
------------------------------
	Writer: yueyuweihu
	Blog: prayyueyu.github.io
------------------------------

*/
