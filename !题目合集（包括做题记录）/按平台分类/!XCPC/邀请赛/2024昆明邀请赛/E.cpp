#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, k, a[N], f[N];

void solve() {
	std::cin >> n >> k;
	int ans = 0, t = 0;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
		ans = std::__gcd(ans, a[i]);
	}
	f[n + 1] = 0;
	f[n] = std::abs(a[n] - a[n - 1]);
	for(int i = n - 1; i >= 1; i--) {
		f[i] = std::__gcd(f[i + 1], std::abs(a[i] - a[i - 1]));
	}
	int g = a[1];
	for(int i = 2; i <= n; i++) {
		int gx = std::__gcd(std::abs(a[i] - a[i - 1]), g);
		if(gx == g) continue;
		gx = std::__gcd(std::abs(a[i] + k - a[i - 1]), g);
		for(int j = i + 1; j <= n; j++) {
			ans = std::max(ans, std::__gcd(std::__gcd(gx, std::abs(a[j] - a[j - 1] - k)), f[j + 1]));
			gx = std::__gcd(std::abs(a[j] - a[j - 1]), gx);
		}
		g = std::__gcd(g, std::abs(a[i] - a[i - 1]));
	}
	g = 0;
	f[n + 1] = 0;
	for(int i = n; i >= 1; i--) f[i] = std::__gcd(f[i + 1], a[i]);
	for(int i = 1; i <= n; i++) {
		g = std::__gcd(g, a[i] + k);
		ans = std::max(ans, std::__gcd(g, f[i + 1]));
	}
	
	g = 0;
	for(int i = 1; i <= n; i++) f[i] = std::__gcd(f[i - 1], a[i]);
	for(int i = n; i >= 1; i--) {
		g = std::__gcd(g, a[i] + k);
		ans = std::max(ans, std::__gcd(g, f[i - 1]));
	}
	std::cout << ans << '\n';
}
signed main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(0);
//	std::cout.tie(0);
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
----------------------
	Writer: ÔÂö§Þ±‹¬ | 
----------------------

2
6 2
5 3 13 8 10 555
3 0
3 6 9
*/
