#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, ne[N], to[N], fi[N], num, d[N], ru[N];
int read() {
//	int x = 0, f = 1;
//	char ch = getchar();
//	while(ch < '0' || ch > '9') {
//		if(ch == '-') f = -1;
//		ch = getchar();
//	}
//	while(ch >= '0' && ch <= '9') {
//		x = x * 10 + ch - '0';
//		ch = getchar();
//	}
//	return x * f;
	int x;
	std::cin >> x;
	return x;
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
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) {
		int k = read();
		for(int j = 1; j <= k; j++) {
			int v = read();
			add(i, v);
			ru[v]++;
		}
	}
	int s = 0;
	for(int i = 1; i <= n; i++) {
		if(!ru[i]) {
			s = i;
			break;
		}
	}
	dfs(s, 0);
	int maxn = -1, id = 0;
	for(int i = 1; i <= n; i++) {
		if(maxn < d[i]) {
			maxn = d[i];
			id = i;
		}
	}
	std::cout << id;
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T = 1; 
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
