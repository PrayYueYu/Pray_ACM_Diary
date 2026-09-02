#include<bits/stdc++.h>
#define int long long
void solve() {
	int x, y;
	std::cin >> x >> y;
	std::cout << 100 - x - y << '\n';
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int T = 1;
//	std::cin >> T;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
