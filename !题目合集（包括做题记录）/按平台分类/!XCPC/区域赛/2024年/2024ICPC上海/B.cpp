#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 9e6 + 100, M = 998244353, INF = 1e16; 
int n, fa[N], vis[N], to[N], ne[N], fi[N], f[N], num, m, p[N];
int ansx[N], ansy[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
map<pair<int, int>, int> mp;
void add(int u, int v) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
}
void solve() {
	n = read(), m = read();
	for(int i = 1; i <= m; i++) {
		int u = read(), v = read();
		add(u, v); add(v, u);
		f[u]++;
		f[v]++;
		mp[{u, v}] = mp[{v, u}] = true;
	}
	for(int i = 1; i <= n; i++) {
		p[i] = read();
	}
	
	int u = 1, nx = 2, tot = 0;
	while(true) {
		if(nx == n + 1) break;
		if(!vis[p[u]]) {
			vis[p[u]] = true;
			for(int i = fi[p[u]]; i; i = ne[i]) {
				int v = to[i];
				f[v]--;
			}
		}
		if(mp[{p[u], p[nx]}]) {
			//f[p[u]]--;
			fa[nx] = u;
			u = nx;
			nx++;
			continue;
		}
		
		if(!f[p[u]]) {
			if(!fa[u]) {
				fa[nx] = u;
				u = nx;
				nx++;
				continue;
			}
			u = fa[u];
			continue;
		}
		ansx[++tot] = p[u];
		ansy[tot] = p[nx];
		add(p[nx], p[u]);
		add(p[u], p[nx]);
		f[p[u]]++;
		mp[{p[u], p[nx]}] = mp[{p[nx], p[u]}] = true;
		fa[nx] = u;
		u = nx;
		nx++;
	}
	cout << tot << endl;
	for(int i = 1; i <= tot; i++) {
		cout << ansx[i] << " " << ansy[i] << endl;
	}
}
signed main() {
	//freopen("1.in", "r", stdin);
	int T = 1;
	while(T--) {
		solve();
	//	init();
	}
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*

*/
