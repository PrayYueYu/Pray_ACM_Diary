#include<bits/stdc++.h>
//#define getchar getchar_unlocked
#define int long long
using namespace std;
const int N = 2e6 + 10, M = 1e9 + 7, INF = 1e18;
int ne[N], to[N], fi[N], num, w[N];
int n, m, k, cnt[N];
int fa[N], top[N], dep[N], sz[N], dfn[N], rk[N], son[N];
int idx, d[N], wx[N];
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x * f;
}
void add(int u, int v, int c) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
	w[num] = c;
}
void dfs1(int u, int f) {
	fa[u] = f;
	dep[u] = dep[f] + 1;
	sz[u] = 1;
	int maxn = -1;
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == f) continue;
		wx[v] = w[i];
		dfs1(v, u);
		if(sz[v] > maxn) {
			maxn = sz[v];
			son[u] = v;
		}
		sz[u] += sz[v];
	}
}
void dfs2(int u, int ftop) {
	top[u] = ftop;
	dfn[u] = ++idx;
	rk[idx] = u;
	if(son[u]) dfs2(son[u], ftop);
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == fa[u] || v == son[u]) continue;
		dfs2(v, v);
	}
}

void Path_Add(int x, int y) {
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		d[dfn[top[x]]]++;
		d[dfn[x] + 1]--;
		x = fa[top[x]];
		//top[x]->x路径
		//注意！fa[top[x]]->top[x]也要加！
		//所以是d[dfn[top[x]]]++
		//而不是d[dfn[top[x]]+1]++
	}
	if(dep[x] > dep[y]) swap(x, y);
//	cout << dfn[u] << ' ' << dfn[v] << '\n';
	d[dfn[x] + 1]++;
	d[dfn[y] + 1]--;
}
priority_queue<pair<int, int>> q;
void solve() {
	n = read(), m = read(), k = read();
	for(int i = 1; i < n; i++) {
		int u = read(), v = read(), c = read();
		add(u, v, c); add(v, u, c);
	}
	dfs1(1, 0);
	dfs2(1, 1);
	int las = 1;
	for(int i = 1; i <= m; i++) {
		int now = read();
		Path_Add(las, now);
		las = now;
	}
	for(int i = 1; i <= n; i++) {
		d[i] += d[i - 1];
		cnt[rk[i]] = d[i];
	}
	for(int i = 1; i <= n; i++) {
		if(cnt[i])
			q.push({cnt[i] * (wx[i] - wx[i] / 2), i});
	}
	for(int i = 1; i <= k; i++) {
		if(q.empty()) break;
		int s = q.top().first;
		int u = q.top().second;
		q.pop();
		wx[u] /= 2;
		if(wx[u])
			q.push({cnt[u] * (wx[u] - wx[u] / 2), u});
	}
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		sum += cnt[i] * wx[i];
	}
	cout << sum;
}
signed main() {
	int T = 1;
	while(T--) solve();
	return 0;
}
/*
	Writer: yueyu_weihu
	Blog: prayyueyu.github.io
*/
