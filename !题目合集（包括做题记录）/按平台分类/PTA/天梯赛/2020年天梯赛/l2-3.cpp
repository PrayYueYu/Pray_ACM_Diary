#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int n, f[N], a[N], cnt;
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
void dfs(int x, int fa) {
	if(x > n) return;
	dfs(x * 2, x);
	dfs(x * 2 + 1, x);
	f[x] = a[++cnt];
}
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	dfs(1, 0);
	for(int i = 1; i <= n; i++) {
		std::cout << f[i];
		if(i != n) std::cout << ' ';
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
------------------------------
	Writer: yueyuweihu
	Blog: prayyueyu.github.io
------------------------------
test:

*/
