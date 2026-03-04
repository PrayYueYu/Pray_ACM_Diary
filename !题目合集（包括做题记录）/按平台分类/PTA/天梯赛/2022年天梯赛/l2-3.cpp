#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;

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
void dfs(int u, int fa) {
	d[u] = d[fa] + 1;
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == fa) continue;
		dfs(v, u);
	}
}
void get_true(int x) {
	while(true) {
		if(vis[x]) break;
		vis[x] = true;
		x = fa[x];
	}
}
void solve() {
	n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		int f = read();
		fa[i] = f;
		if(f != -1) {
			add(f, i);
			add(i, f);
		}
		else s = i;
	}
	dfs(s, 0);
	int nowfa = 0;
	std::priority_queue<int> q;
	for(int i = 1; i <= m; i++) {
		int x = read();
		if(vis[x]) {
			std::cout << 
			continue;
		}
		if(i == 1) {
			nowfa = x;
			std::cout << d[x] << '\n';
			sum += d[x];
			q.push(-d[x]);
			get_true(x);
			continue;
		}
		get_true(x);
		nowfa = ...;
		
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
