#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int n, m, q;
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

void solve() {
	n = read(), m = read(), q = read();
	std::vector<std::vector<int>> vis;
	vis.resize(n + 5, std::vector<int>(m + 5));
	int res = n * m;
	for(int i = 1; i <= q; i++) {
		int op = read(), c = read();
		if(op) {
			for(int j = 1; j <= n; j++) {
				if(!vis[j][c]) {
					vis[j][c] = true;
					res--;
				}
			}
		}
		else {
			for(int j = 1; j <= m; j++) {
				if(!vis[c][j]) {
					vis[c][j] = true;
					res--;
				}
			}
		}
	}
	std::cout << res;
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
------------------------------
	Writer: yueyuweihu
	Blog: prayyueyu.github.io
------------------------------
test:

*/
