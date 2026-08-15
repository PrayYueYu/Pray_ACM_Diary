#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int ans, n, m, sum1[N], sum2[N];
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
	std::cin >> n >> m;
	ans = n;
	for(int i = 1; i <= m; i++) {
		int x, y;
		std::cin >> x >> y;
		sum2[x]++;
		sum1[y]++;
	}
	for(int i = 1; i <= n; i++) {
		ans = std::min(n - sum1[i], ans);
		ans = std::min(ans, n - sum2[i]);
	}
	std::cout << ans; 
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
	Writer: ÔÂö§Þ±‹¬ | 
----------------------
*/
