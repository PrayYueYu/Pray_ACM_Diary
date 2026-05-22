#include<bits/stdc++.h>
#define int long long
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int n, m, ne[N], to[N], fi[N], num, vis[N];
int fa[N][22], f1[N][22], f2[N][22], dep[N], d[N];
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
void get_MinD() {
	std::queue<int> qu;
	for(int i = 1; i <= m; i++) {
		int x = read();
		vis[x] = true;
		qu.push(x);
	}
	while(!qu.empty()) {
		int u = qu.front();
		qu.pop();
		for(int i = fi[u]; i; i = ne[i]) {
			int v = to[i];
			if(vis[v]) continue;
			d[v] = d[u] + 1;
			vis[v] = true;
			qu.push(v);
		}
	}
}
void dfs(int u, int fat) {
	dep[u] = dep[fat] + 1;
	fa[u][0] = fat;
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == fat) continue;
		dfs(v, u);
	}
} 
void init_ST() {
	for(int i = 1; i <= n; i++) {
		f1[i][0] = std::min(3 * d[i] - dep[i], 3 * d[fa[i][0]] - dep[fa[i][0]]);
		f2[i][0] = std::min(3 * d[i] + dep[i], 3 * d[fa[i][0]] + dep[fa[i][0]]);
	}
	for(int j = 0; j <= 20; j++) {
		f1[0][j] = INF;
		f2[0][j] = INF;
	}
	for(int j = 1; j <= 20; j++) {
		for(int i = 1; i <= n; i++) {
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
			f1[i][j] = std::min(f1[i][j - 1], f1[fa[i][j - 1]][j - 1]);
			f2[i][j] = std::min(f2[i][j - 1], f2[fa[i][j - 1]][j - 1]);
		}
	}
}
int LCA(int x, int y) {
    if(dep[x] < dep[y]) std::swap(x, y);
    for(int i = 20; i >= 0; i--) {
        if(dep[fa[x][i]] >= dep[y]) {
            x = fa[x][i];
        }
    }
    if(x == y) return x;
    for(int i = 20; i >= 0; i--) {
        if(fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}
void solve() {
	n = read(), m = read();
	for(int i = 1; i < n; i++) {
		int u = read(), v = read();
		add(u, v), add(v, u);
	}
	get_MinD();//求每个点到最近的骑行点的距离
	dfs(1, 0);//求每个点的depth 和 father 
	init_ST();//倍增初始化 
	int q = read();
	for(int i = 1; i <= q; i++) {
		int x = read(), y = read();
		int lca = LCA(x, y);
		int minn1 = 3 * d[x] - dep[x];
		int minn2 = 3 * d[y] + dep[y];
		int now = x;
		for(int j = 20; j >= 0; j--) {
			if(dep[fa[now][j]] < dep[lca]) continue;
			minn1 = std::min(minn1, f1[now][j]);
			now = fa[now][j];
		}
		now = y;
		for(int j = 20; j >= 0; j--) {
			if(dep[fa[now][j]] < dep[lca]) continue;
			minn2 = std::min(minn2, f2[now][j]);
			now = fa[now][j];
		}
		minn1 = minn1 + dep[x];
		minn2 = minn2 + dep[x] - 2 * dep[lca];
		int ans = std::min(minn1, minn2);
		int t = dep[x] + dep[y] - 2 * dep[lca];
		ans = ans + t;
		ans = std::min(ans, 2 * t);
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
