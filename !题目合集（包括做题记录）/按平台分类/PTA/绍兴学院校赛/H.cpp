#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, m, a[N], fa[N], cnt[N];
int read() {
	int x;
	std::cin >> x;
	return x;
}
struct S {
	int u, v, w;
} s[N];
bool cmp(S x, S y) {
	return x.w > y.w;
}
int getfa(int x) {
	if(x == fa[x]) return fa[x];
	return fa[x] = getfa(fa[x]);
}
void solve() {
	n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		fa[i] = i;
		cnt[i] = 1;
	}
	for(int i = 1; i <= m; i++) {
		int u = read(), v = read();
		s[i].u = u, s[i].v = v;
		s[i].w = std::min(a[u], a[v]);
	}
	std::sort(s + 1, s + m + 1, cmp);
	int ans = 0;
	for(int i = 1; i <= m; i++) {
		int fau = getfa(s[i].u);
		int fav = getfa(s[i].v);
		if(fau == fav) continue;
		fa[fau] = fav;
		ans += s[i].w * cnt[fau] * cnt[fav];
		cnt[fav] += cnt[fau];
	}
	ans *= 2;
	printf("%.10lf\n", (double)ans / (double)(n * (n - 1)));
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
