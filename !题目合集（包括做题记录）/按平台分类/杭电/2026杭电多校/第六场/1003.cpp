#include<bits/stdc++.h>
#define int long long
const int N = 1e7 + 10, mod = 998244353, INF = 1e18;
int g[N], p[N], a[2000010], n, cnt, phi[N], B = 1000;
int ans[1010], maxn = N - 10;
bool vis[N];
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
	for(int i = 0; i < B; i++) ans[i] = 0;
	for(int i = 0; i <= maxn; i++) g[i] = 0;
}
void pre() {
	for(int i = 0; i <= maxn; i++) phi[i] = i;
	for(int i = 2; i <= maxn; i++) {
	    if(phi[i] == i) {
	        for(int j = i; j <= maxn; j += i)
	            phi[j] = phi[j] / i * (i - 1);
	    }
	}
	for(int i = 2; i <= maxn; i++) {
		if(!vis[i]) p[++cnt] = i;
		for(int j = 1; j <= cnt; j++) {
			if(i * p[j] > maxn) break;
			vis[i * p[j]] = true;
			if(i % p[j] == 0) break;
		}
	}
}
int up(int x, int y) {
	if(x % y == 0) return x / y;
	return x / y + 1;
}
void solve() {
	std::cin >> n;
	for(int i = 1; i <= n; i++) std::cin >> a[i];
	for(int i = 1; i <= n; i++) g[a[i]] = phi[a[i]];
	for(int i = 1; i <= cnt; i++) {
		for(int d = maxn / p[i]; d >= 1; d--) {
			g[d] = std::max(g[d], g[d * p[i]]);
		}
	}
	for(int i = 1; i <= maxn; i++) {
		g[i] = g[i] * i / phi[i];
	}
	for(int i = 1; i <= cnt; i++) {
		for(int d = 1; d <= maxn / p[i]; d++) {
			g[d * p[i]] = std::max(g[d * p[i]], g[d]);
		}
	}
	for(int x = 1; x <= maxn; x++) {
		int now = phi[x] * g[x] * up(x, B);
		ans[(x % B)] ^= now;
	}
	for(int i = 0; i < B; i++) std::cout << ans[i] << '\n';
}
signed main() {
	pre();
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*
----------------------
	Writer: ÔÂö§Þ±‹¬ | 
----------------------
*/
