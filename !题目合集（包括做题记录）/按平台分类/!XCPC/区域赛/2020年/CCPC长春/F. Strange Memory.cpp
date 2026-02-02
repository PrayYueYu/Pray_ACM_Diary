#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 1e6 + 100, M = 998244353, INF = 1e18; 
int n, k, a[N], ans;
int ne[N], to[N], num, cnt[N], fi[N], fa[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
void add(int u, int v) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
}
int getfa(int x) {
	if(x == fa[x]) return x;
	return fa[x] = getfa(fa[x]);
}
map<int, vector<int>> mp[N];
vector<int> dsu[N];
void merge(int u, int v, int Lca) {
	int fau = getfa(u);
	int fav = getfa(v);
	if(cnt[fau] > cnt[fav]) swap(fau, fav);
	for(auto x: dsu[fau]) {
		int newv = a[x] ^ Lca;
		for(auto z: mp[fav][newv]) {
			ans += x ^ z;
		}
	}
	cnt[fav] += cnt[fau];
	fa[fau] = fav;
	for(auto x: mp[fau]) {
		for(auto y: x.second) {
			mp[fav][x.first].push_back(y);
		}
	}
	for(auto x: dsu[fau]) {
		dsu[fav].push_back(x);
	}
}
void dfs(int u, int Fa) {
	mp[u][a[u]].push_back(u);
	dsu[u].push_back(u);
	cnt[u]++;
	fa[u] = u;
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == Fa) continue;
		dfs(v, u);
		merge(u, v, a[u]);
	}
	
}
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
	}
	for(int i = 1; i < n; i++) {
		int u = read(), v = read();
		add(u, v);
		add(v, u);
	}
	dfs(1, 0);
}
signed main() {
	//freopen("1.in", "r", stdin);
	int T = 1;
	while(T--) {
		solve();
	} 
	cout << ans;
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*

*/
