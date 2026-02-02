#include<bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10;
int n, a[N], b[N], ans[N];
int fi[N], num, to[N], ne[N];
int fa[N], cnt[N], val[N], sum[N];
vector<int> dsua[N], dsub[N];
map<int, int> mp[N];
int read() {
	int x;
	cin >> x;
	return x;
}
void init() {
	for(int i = 1; i <= n; i++) {
		fi[i] = 0;
		mp[i].clear();
		dsua[i].clear();
		dsub[i].clear();
		sum[i] = 0;
	}
	for(int i = 0; i <= num + 2; i++) {
		ne[i] = to[i] = 0;
	}
	num = 0;
}
void add(int u, int v) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
}
int getfa(int x) {
	if(fa[x] == x) return x;
	return fa[x] = getfa(fa[x]);
}
void merge(int u, int v) {
	int fau = getfa(u), fav = getfa(v);
	if(fau == fav) return;
	if(cnt[fau] > cnt[fav]) swap(fau, fav);
	for(auto x: dsua[fau]) {
		if(mp[fav][x] < 0) sum[fav]--;
		mp[fav][x]++;
		dsua[fav].push_back(x);
	}
	for(auto x: dsub[fau]) {
		if(x) {
			mp[fav][x]--;
			if(mp[fav][x] < 0) {
				sum[fav]++;
			}
		}
		dsub[fav].push_back(x);
	}
	fa[fau] = fav;
	cnt[fav] += cnt[fau];
}
void dfs(int u, int fa) {
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == fa) continue;
		dfs(v, u);
		merge(u, v);
	}
	int fau = getfa(u), f = false;
	if(mp[fau][0] >= sum[fau]) f = true;
	ans[u] = f;
}
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= n; i++) b[i] = read();
	for(int i = 1; i <= n; i++) {
		dsua[i] = {a[i]};
		dsub[i] = {b[i]};
		mp[i][a[i]]++;
		if(b[i]) {
			mp[i][b[i]]--;
			if(mp[i][b[i]] < 0) sum[i]++;
		}
		cnt[i] = 1;
		fa[i] = i;
	}
	for(int i = 1; i < n; i++) {
		int u = read(), v = read();
		add(u, v), add(v, u);
	}
	dfs(1, 0);
	for(int i = 1; i <= n; i++) cout << ans[i];
	cout << '\n';
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
1
6
1 5 0 3 4 0
0 3 4 5 2 0
1 2
2 3
2 4
1 5
5 6
*/
