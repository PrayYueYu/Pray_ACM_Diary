#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 100, INF = 1e18;
int n, a[N], t[N], fa[N], cnt[N];
int ne[N], to[N], fi[N], num, ans[N], ed[N], f[N];
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
vector<int> dsu[N];
void add(int u, int v) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
}
int getfa(int x) {
	if(fa[x] == x) return x;
	return fa[x] = getfa(fa[x]);
}
int calc(int u, int v) {
	if(f[u] == f[v]) return INF;
	return abs(a[u] - a[v]);
}
void merge(int u, int v) {
	int fau = getfa(u), fav = getfa(v);
	if(fau == fav) return;
	if(cnt[fau] > cnt[fav]) swap(fau, fav);
	fa[fau] = fav;
	cnt[fav] += cnt[fau];
	for(auto x: dsu[fau]) {
		dsu[fav].push_back(x);
	}
}
void dfs(int u, int fa) {
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == fa) continue;
		if(ans[v]) continue;
		if(f[u] == f[v]) {
			ed[v] = ed[u];
			ans[v] = abs(ed[u] - a[v]);
		}
		else {
			int x = (a[v] + a[u]) / 2;
			if(a[u] < a[v]) {
				if(x > ed[u]) {
					ed[v] = ed[u];
					ans[v] = abs(ed[u] - a[v]);
				}
				else {
					ed[v] = x;
					ans[v] = abs(x - a[v]);
				}
			}
			else {
				if(x < ed[u]) {
					ed[v] = ed[u];
					ans[v] = abs(ed[u] - a[v]);
				}
				else {
					ed[v] = x;
					ans[v] = abs(x - a[v]);
				}
			}
		}
		dfs(v, u);
	}
}
priority_queue<pair<int, int>> q;
signed main() {
	n = read();
	for(int i = 1; i <= n; i++) {
		fa[i] = i;
		cnt[i] = 1;
		dsu[i] = {i};
	}
	for(int i = 1; i <= n; i++) {
		t[i] = read();
		add(t[i], i);
		merge(t[i], i);
	}
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		a[i] *= 2;
	}
	for(int i = 1; i <= n; i++) {
		if(a[i] > a[t[i]]) {
			f[i] = 0;//0->left
		}
		else f[i] = 1;//1->right
	}
	for(int i = 1; i <= n; i++) {
		int fi = getfa(i);
		if(fi != i) continue;
		
		for(auto u: dsu[i]) {
			if(f[u] != f[t[u]]) {
				q.push({-abs(a[u] - a[t[u]]), u});
			}
		}
		while(!q.empty()) {
			int u = q.top().second;
			q.pop();
			if(ans[u]) continue;
			ed[u] = (a[u] + a[t[u]]) / 2;
			ans[u] = abs(a[u] - ed[u]);
			dfs(u, 0);
		}
		for(auto u: dsu[i]) {
			if(!ans[u]) {
				ans[u] = abs(ed[t[u]] - a[u]);
			}
		}
	}
	
	for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
	return 0;
}
