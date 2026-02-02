#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int n, ne[N], to[N], fi[N], num, cnt[N], d[N];
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
void init() {
	for(int i = 0; i <= num + 5; i++) {
		to[i] = ne[i] = 0;
	}
	num = 0;
	for(int i = 0; i <= n + 5; i++) {
		fi[i] = cnt[i] = 0;
	}
}
void add(int u, int v) {
	ne[++num] = fi[u];
	fi[u] = num;
	to[num] = v;
}
void dfs(int u, int fa) {
	d[u] = d[fa] + 1;
	cnt[d[u]]++;
	for(int i = fi[u]; i; i = ne[i]) {
		int v = to[i];
		if(v == fa) continue;
		dfs(v, u);
	}
}
void solve() {
	n = read();
	for(int i = 1; i < n; i++) {
		int u = read(), v = read();
		add(u, v);
		add(v, u);
	}
	d[0] = 0;
	dfs(1, 0);
	int maxn = -1;
	for(int i = 1; i <= n; i++) {
		if(maxn < cnt[i]) {
			maxn = cnt[i];
		}
	}
	for(int i = 1; i <= n; i++) {
		int val = -1;
		if(i == 1) val = 0;
		for(int j = fi[i]; j; j = ne[j]) {
			val++;
		}
		if(val == cnt[d[i] + 1] && val == maxn) {
			std::cout << maxn + 1 << '\n';
			return;
		}
	}
	std::cout << maxn << '\n';
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
------------------------------
	Writer: yueyuweihu
	Blog: prayyueyu.github.io
------------------------------
test:

*/
