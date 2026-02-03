#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 100, M = 1e9 + 7;
int ans, ne[N], to[N], fi[N], num, sz[N], a[N], n;
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
	if(!a[u]) sz[u] = 0;
}
void dfs(int u, int fa) {
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == fa) continue;
		if(a[u]) sz[u] -= sz[v];
		if(a[v]) sz[v] += sz[u];
		dfs(v, u);
		if(a[v]) sz[v] -= sz[u];
		if(a[u]) sz[u] += sz[v];
	}
	if(a[u]) return;
	int sum = 0;
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		sum += sz[v];
	}
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		sum -= sz[v];
		ans += sum * sz[v];
		ans += sz[v];
	}
}
signed main() {
	n = read();
	for(int i = 1; i <= n; i++) {
		char ch;
		cin >> ch;
		if(ch == 'W') a[i] = 1;//°×É« 
		else a[i] = 0;//ºÚÉ« 
	}
	for(int i = 1; i < n; i++) {
		int u = read(), v = read();
		add(u, v);
		add(v, u);
	}
	init(1, 0);
	dfs(1, 0);
	cout << ans;
	return 0;
}
