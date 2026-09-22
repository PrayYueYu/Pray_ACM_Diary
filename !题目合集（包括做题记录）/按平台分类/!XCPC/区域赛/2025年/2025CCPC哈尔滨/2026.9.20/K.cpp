#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;

void solve() {
	int w;
	std::cin >> w;
	std::cout << w << '\n';
	for(int i = 1; i <= w; i++) std::cout << i << ' ';
	std::cout << '\n';
	std::cout << w << ' ';
	for(int i = 2; i <= w; i++) {
		std::cout << (i - 1) * (w + 1) << ' ';
	}
}
signed main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(0);
//	std::cout.tie(0);
	int T = 1; 
//	std::cin >> T;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
----------------------
	Writer: ÔÂö§Ş±‹¬ | 
----------------------
*/
