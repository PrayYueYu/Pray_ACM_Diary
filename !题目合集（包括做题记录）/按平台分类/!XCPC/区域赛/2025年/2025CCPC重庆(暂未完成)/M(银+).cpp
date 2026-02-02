#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N1 = 1e6 + 10, N2 = 2e5 + 100;
int vis[N1], pri[N1], idp[N1], cnt;//prime
int n, a[N2], ans[N2], u[N2], v[N2];//main
int tr[200][N2];//树状数组 
int sz[N2], dfn[N2], top[N2], fa[N2], dep[N2], rk[N2], idx, son[N2];//树链剖分 
vector<int> pa[N1];//边
set<int> sp[N1]; //>1000质数在哪些点出现过（存dfn序） 
int read() {
	int x;
	cin >> x;
	return x;
}
void init() {
	for(int i = 2; i <= 1000000; i++) {
		if(!vis[i]) {
			vis[i] = i;
			pri[++cnt] = i;
			idp[i] = cnt;//质数序号离散化 
		}
		for(int j = 1; ; j++) {
			if(i * pri[j] > 1000000) break;
			vis[i * pri[j]] = pri[j];
			if(i % pri[j] == 0) break;
		}
	}
}
int lowbit(int x) {
	return x & (-x);
}
void add(int x, int y, int p) {//质数p的树状数组，序号x的增加y
	while(x <= n) {
		tr[idp[p]][x] += y;
		x += lowbit(x);
	}
}
int query(int x, int p) {//1~x前缀和 
	int ans = 0;
	while(x) {
		ans += tr[idp[p]][x];
		x -= lowbit(x);
	}
	return ans;
}
void dfs1(int u, int f) {
	dep[u] = dep[f] + 1;
	sz[u] = 1;
	fa[u] = f;
	int Max = 0;
	for(auto v: pa[u]) {
		if(v == f) continue;
		dfs1(v, u);
		if(Max < sz[v]) {
			Max = sz[v];
			son[u] = v;
		}
		sz[u] += sz[v];
	}
}
void dfs2(int u, int ftop) {
	dfn[u] = ++idx;
	rk[idx] = u;
	top[u] = ftop;
	if(son[u]) dfs2(son[u], ftop);
	for(auto v: pa[u]) {
		if(v == fa[u] || v == son[u]) continue;
		dfs2(v, v);
	}
}
int tr_query1(int x, int y, int p) {
	int sum = 0;
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		sum += query(dfn[x], p) - query(dfn[top[x]] - 1, p);
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) swap(x, y);
	sum += query(dfn[y], p) - query(dfn[x] - 1, p);
	return sum;
}

int tr_query2(int x, int y, int p) {
	int F = false;
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		auto it = sp[p].lower_bound(dfn[top[x]]);
		if(it != sp[p].end()) {
			if((*it) <= dfn[x]) F = true;
		}
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) swap(x, y);
	auto it = sp[p].lower_bound(dfn[x]);
	if(it != sp[p].end()) {
		if((*it) <= dfn[y]) F = true;
	}
	return F;
}
void Insert(int u, int x) {
	ans[u] = x;
	while(true) {
		if(x == 1) break;
		int p = vis[x];
		if(p > 1000) {
			sp[p].insert(dfn[u]);
			x /= p;
			continue;
		}
		int num = 0;
		while(true) {
			if(x % p == 0) {
				num++;
				x /= p;
			}
			else break;
		}
		add(dfn[u], num, p);
	}
}
signed main() {
	init();
	n = read(); int c1 = read();
	for(int i = 1; i < n; i++) {
		a[i] = read();
		u[i] = read();
		v[i] = read();
		pa[v[i]].push_back(i + 1);
		pa[i + 1].push_back(v[i]);
	}
	dfs1(1, 0);
	dfs2(1, 1);
	Insert(1, c1);
	for(int i = 1; i < n; i++) {
		int now = a[i];
		while(true) {
			if(now == 1) break;
			int p = vis[now];
			if(p > 1000) {
				if(tr_query2(u[i], v[i], p)) {
					a[i] /= p;
				}
				now /= p;
				continue;
			}
			while(true) {
				if(now % p == 0) {
					now /= p;
				}
				else break;
			}
			int num = tr_query1(u[i], v[i], p);
			
			for(int j = 1; j <= num; j++) {
				if(a[i] % p == 0) a[i] /= p;
				else break;
			}
		}
		
		Insert(i + 1, a[i]);
	}
	for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
	return 0;
} 
/*
5 10
6 1 1
2 2 2
35 1 2
84 3 4
*/
