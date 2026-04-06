#include<bits/stdc++.h>
#define int long long
const int N = 2e5 + 10, mod = 998244353, INF = 1e18;
int n, m, r[N], rx[N], vis[N];
int ne[N], to[N], fi[N], num;
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
void solve() {
	n = read(), m = read();
	for(int i = 1; i <= m; i++) {
		int u = read(), v = read();
		add(u, v); 
		add(v, u);
		r[u]++;
		r[v]++;
	}
	int q = read();
	for(int i = 1; i <= q; i++) {
		for(int j = 1; j <= n; j++) {
			rx[j] = r[j];
			vis[j] = false;
		}
		int np = read();
		for(int j = 1; j <= np; j++) {
			int x = read();
			if(vis[x]) continue;
			vis[x] = true;
			for(int k = fi[x]; k; k = ne[k]) {
				int v = to[k];
				rx[v]--;
			}
		}
		int f = true;
		for(int j = 1; j <= n; j++) {
			if(vis[j]) continue;
			if(rx[j]) f = false;
		}
		if(f) std::cout << "YES\n";
		else std::cout << "NO\n";
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
