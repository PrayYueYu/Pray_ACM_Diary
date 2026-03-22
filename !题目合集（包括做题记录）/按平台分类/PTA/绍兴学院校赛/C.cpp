#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n;
void solve() {
	std::cin >> n;
	int la = 0, lb = 0, ans = 1, a, b;
	for(int i = 1; i <= n; i++) {
		std::cin >> a >> b;
		ans += std::max(0ll, std::min(a, b) - std::max(la, lb) + 1);
		if(la == lb) ans--;
		la = a, lb = b;
	}
	std::cout << ans;
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
