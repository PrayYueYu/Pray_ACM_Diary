#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, m, f[N], to[N];
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
struct S {
	int c, v;
} s[N];
bool cmp(S x, S y) {
	if(x.v == y.v) return x.c < y.c;
	return x.v < y.v;
}
void solve() { 
	n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		s[i].c = read(), s[i].v = read();
	}
	std::sort(s + 1, s + n + 1, cmp);
	for(int i = 1; i <= n; i++) {
		int minn = INF, id = n + 1;
		for(int j = i + 1; j <= n; j++) {
			if(minn > s[j].c) {
				minn = s[j].c;
				id = j;
			}
		}
		to[i] = id;
	}
	f[0] = 0;
	for(int i = 1; i <= m; i++) f[i] = -INF;
	for(int i = 1; i <= m; i++) {
		f[i] = f[i - 1];
		for(int j = 1; j < n; j++) {
			int sumc = s[j].c + s[to[j]].c;
			if(i - sumc < 0) continue;
			f[i] = std::max(f[i], f[i - sumc] + s[j].v);
		}
	}
	std::cout << f[m];
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
