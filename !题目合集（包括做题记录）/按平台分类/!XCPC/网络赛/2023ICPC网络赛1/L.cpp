#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, ans;
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
int calc(int x, int y) {
	if(x % y == 0) return x / y;
	return x / y + 1;
}
void solve() {
	int T = 0, maxn = 0;
	std::cin >> n >> T;
	for(int i = 1; i <= n; i++) {
		int x;
		std::cin >> x;
		maxn = std::max(maxn, x);
	}
	std::cout << std::max(2ll, calc(maxn, T));
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
