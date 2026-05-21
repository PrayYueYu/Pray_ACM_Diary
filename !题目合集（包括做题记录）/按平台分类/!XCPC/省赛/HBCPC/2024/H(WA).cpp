#include<bits/stdc++.h>
#define int long long
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int n, ne[2 * N], fi[2 * N], to[2 * N], w[2 * N];
int m, fa[N], dep[N], f[N][22], len[N], num, cnt;
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
struct Edge {
	int u, v, w;
} s[3 * N];
bool cmp(Edge x, Edge y) {
	return x.w < y.w;
}
void add(int u, int v, int d) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
	w[num] = d;
}
int getfa(int x) {
	if(x == fa[x]) return x;
	return fa[x] = getfa(fa[x]);
}
void build_MST() {
	for(int i = 1; i <= 2 * n; i++) fa[i] = i;
	std::sort(s + 1, s + cnt + 1, cmp);
	for(int i = 1; i <= cnt; i++) {
		int fau = getfa(s[i].u);
		int fav = getfa(s[i].v);
		if(fau == fav) continue;
		fa[fav] = fau;
		add(s[i].u, s[i].v, s[i].w);
		add(s[i].v, s[i].u, s[i].w);
//		std::cout << s[i].u << ' ' << s[i].v << ' ' << s[i].w << '\n';
	}
}
void dfs(int u, int fa, int d) {
    dep[u] = d; f[u][0] = fa;
    for(int i = fi[u]; i; i = ne[i]) {
        int v = to[i];
        if(v == fa) continue;
        len[v] = len[u] + w[i];
        dfs(v, u, d + 1);
    }
}
void init_LCA() {
	dfs(1, 0, 1);
    for(int j = 1; j <= 20; j++) {
    	for(int i = 1; i <= 2 * n; i++) {
            f[i][j] = f[f[i][j - 1]][j - 1];
        }
    }
}
int LCA(int x, int y) {
    if(dep[x] < dep[y]) std::swap(x, y);
    for(int i = 20; i >= 0; i--) { 
        if(dep[f[x][i]] >= dep[y]) {
            x = f[x][i];
        }
    }
    if(x == y) return x;
    for(int i = 20; i >= 0; i--) {
        if(f[x][i] != f[y][i]) {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];	
}
void solve() {
	n = read(), m = read();
	for(int i = 1; i < n; i++) {
		int u = read(), v = read();
		s[++cnt] = {u, v, 2};
		s[++cnt] = {v, u, 2};
		s[++cnt] = {u + n, v + n, 1};
		s[++cnt] = {v + n, u + n, 1};
	}
	for(int i = 1; i <= m; i++) {
		int x = read();
		s[++cnt] = {x, x + n, 0};
		s[++cnt] = {x + n, x, 0};
	}
	build_MST();
	init_LCA();
	int q = read();
	for(int i = 1; i <= q; i++) {
		int x = read(), y = read();
		int s1 = LCA(x, y), s2 = LCA(x, y + n);
//		std::cout << dep[x] << ' ' << dep[y];
//		std::cout << ' ' << dep[s1] << '\n';
		s1 = len[x] + len[y] - 2 * len[s1];
		s2 = len[x] + len[y + n] - 2 * len[s2];
		int ans = std::min(s1, s2);
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
