#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, a[N];
void solve() {
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
		a[i] = a[i] - i;
	}
	std::sort(a + 1, a + n + 1);
	a[0] = -199999;
	int ans = -1, cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] == a[i - 1]) continue;
		if(a[i] == a[i - 1] + 1) {
			cnt++;
		}
		else {
			cnt = 1;
		}
		ans = std::max(ans, cnt);
//		std::cout << a[i] << ' ' << cnt << '\n';
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
	Writer: ÔÂö§Ş±‹¬ | 
----------------------
*/
