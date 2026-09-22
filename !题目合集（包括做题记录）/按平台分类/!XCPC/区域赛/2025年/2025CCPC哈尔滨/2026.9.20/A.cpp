#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, a[N];

void solve() {
	std::cin >> n;
	int g = 0, gx = 0;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
		if(i >= 2)
			g = std::__gcd(g, std::abs(a[i] - a[i - 1]));
		gx = std::__gcd(gx, a[i]);
	}
	if(!g) {
		std::cout << "infinite\n";
		return;
	}
	std::cout << g << ' ' << g / gx << '\n';
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
*/
