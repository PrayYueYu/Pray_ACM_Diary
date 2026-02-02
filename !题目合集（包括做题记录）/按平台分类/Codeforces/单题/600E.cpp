#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int N = 2e5 + 100, M = 1e9 + 7, INF = 1e18;
int n, m, ans[N], a[N], fa[N], cnt[N], Max[N], sum[N];
int fi[N], to[N], ne[N], num;
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
vector<int> dsu[N];
map<int, int> mp[N];
void merge(int u, int v) {
	int fau = getfa(u);
	int fav = getfa(v);
	if(cnt[fau] > cnt[fav]) swap(fau, fav);
	for(auto x: dsu[fau]) {
		int co = a[x];
		mp[fav][co]++;
		if(mp[fav][co] > Max[fav]) {
			Max[fav] = mp[fav][co];
			sum[fav] = co;
		}
		else if(mp[fav][co] == Max[fav]) {
			sum[fav] += co;
		}
		dsu[fav].push_back(x);
	}
	cnt[fav] += cnt[fau];
	fa[fau] = fav;
}
void dfs(int u, int fa) {
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == fa) continue;
		dfs(v, u);
		merge(u, v);
	}
	int fau = getfa(u);
	ans[u] = sum[fau];
}
signed main() {
	n = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		fa[i] = i;
		cnt[i] = 1;
		dsu[i].push_back(i);
		mp[i][a[i]]++;
		Max[i] = 1;
		sum[i] = a[i];
	}
	for(int i = 1; i < n; i++) {
		int u = read(), v = read();
		add(u, v);
		add(v, u);
	}
	dfs(1, 0);
	for(int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
    return 0;
}
/*

*/
