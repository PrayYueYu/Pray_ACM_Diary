#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, m, x, y, b[10], c[10];
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
	std::cin >> x >> y >> n >> m;
	b[1] = b[3] = c[1] = c[3] = -INF;
	b[2] = b[4] = c[2] = c[4] = INF;
	for(int i = 1; i <= n; i++) {
		int a; std::cin >> a;
		if(a > 0) {
			b[1] = std::max(b[1], a);
			b[2] = std::min(b[2], a);
		}
		else {
			b[3] = std::max(b[3], a);
			b[4] = std::min(b[4], a);
		}
	}
	for(int i = 1; i <= m; i++) {
		int a; std::cin >> a;
		if(a > 0) {
			c[1] = std::max(c[1], a);
			c[2] = std::min(c[2], a);
		}
		else {
			c[3] = std::max(c[3], a);
			c[4] = std::min(c[4], a);
		}
	}
	int ans = -INF;
	for(int i = 1; i <= 5; i++) {
		if(std::abs(b[i]) == INF) continue;
		for(int j = 1; j <= 5; j++) {
			if(std::abs(c[j]) == INF) continue;
			ans = std::max(ans, (x + b[i]) * (y + c[j]));
		}
	}
	std::cout << ans << '\n';
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
	Writer: ÔÂö§Þ±‹¬ 
*/
