#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5 + 100, INF = 1e18;
int fi[N], ne[N * 2], to[N * 2], num, fa[N];
int n, m, c[N], Min[N][3], id[N][3];
int f[N][22], in[N], out[N], cnt, t[N][22];
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
void add(int u, int v) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
}
void dfs(int u, int F) {
	in[u] = ++cnt;
	if(u > 1) fa[u] = F;
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == F) continue;
		dfs(v, u);
		if(c[v] < Min[u][1]) {
			Min[u][2] = Min[u][1], id[u][2] = id[u][1];
			Min[u][1] = c[v], id[u][1] = v;
		}
		else if(c[v] < Min[u][2]) {
			Min[u][2] = c[v];
			id[u][2] = v;
		}
	}
	c[u] = min(c[u], Min[u][1] + Min[u][2]);
	out[u] = ++cnt;
}
void init() {
	for(int i = 0; i <= num + 3; i++) {
		ne[i] = to[i] = 0;
	}
	for(int i = 1; i <= n; i++) {
		fa[i] = 0, fi[i] = 0;
	}
	num = 0;
}
bool check(int u, int v) {
	if(!u) return true;
	if(u == v) return false;
	if(in[u] <= in[v] && out[u] >= out[v]) return true;
	return false;
}
void solve() {
	n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		c[i] = read();
		Min[i][1] = Min[i][2] = INF;
	}
	for(int i = 1; i < n; i++) {
		int u = read(), v = read();
		add(u, v);
		add(v, u);
	}
	dfs(1, 0);
	for(int i = 2; i <= n; i++) {
		if(id[fa[i]][1] == i) {
			f[i][0] = Min[fa[i]][2];
		}
		else {
			f[i][0] = Min[fa[i]][1];
		}
		t[i][0] = fa[i];
	}
	for(int j = 1; j <= 20; j++) {
		for(int i = 1; i <= n; i++) {
			t[i][j] = t[t[i][j - 1]][j - 1];
			f[i][j] = f[i][j - 1] + f[t[i][j - 1]][j - 1];
		}
	}
	for(int i = 1; i <= m; i++) {
		int u = read(), v = read();
		int ans = 0;
		for(int j = 20; j >= 0; j--) {
			if(check(t[u][j], v)) continue;
			ans += f[u][j];
			u = t[u][j];
		}
		if(u != v) {
			cout << -1 << endl;
			continue;
		}
		cout << ans << endl;
	}
}
signed main() {
	int T = read();
	while(T--){
		 solve();
		 init();
	}
	return 0;
}
