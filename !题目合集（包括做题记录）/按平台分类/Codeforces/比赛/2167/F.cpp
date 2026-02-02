#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 100;
int a[N], n, ans[N], k;
int ne[N], to[N], fi[N], num, sz[N];
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
void init(int u, int fa) {
	sz[u] = 1;
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == fa) continue;
		init(v, u);
		sz[u] += sz[v];
	}
	if(sz[u] >= k) ans[1]++;
}
void dfs(int u, int fa) {
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == fa) continue;
		ans[v] = ans[u];
		if(sz[u] - sz[v] < k) {
			ans[v]--;
		}
		if(sz[v] < k) ans[v]++;
		sz[u] -= sz[v];
		sz[v] += sz[u];
		dfs(v, u);
		sz[v] -= sz[u];
		sz[u] += sz[v];
	}
	if(u == 1) return;
	
}
void solve() {
	n = read(), k = read();
	for(int i = 1; i < n; i++) {
		int u = read(), v = read();
		add(u, v);
		add(v, u);
	}
	init(1, 0);
	dfs(1, 0);
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		sum += ans[i];
		ans[i] = 0;
		sz[i] = 0;
	}
	for(int i = 0; i <= num + 3; i++) {
		ne[i] = to[i] = fi[i] = 0;
	}
	num = 0;
	cout << sum << endl;
}
signed main() {
	int T = read();
	while(T--) {
		solve();
	//	init();
	}
	return 0;
} 
