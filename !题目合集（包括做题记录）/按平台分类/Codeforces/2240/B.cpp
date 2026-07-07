#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, m, r, c;
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
int ksm(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = ans * x % mod;
		y >>= 1;
		x = x * x % mod;
	}
	return ans;
}
void solve() {
	std::cin >> n >> m >> r >> c;
	int ans = ksm(2, (r + c - 1));
	ans = ans * (ksm(2, n + m - r - c)) % mod;
	std::cout << ans << '\n';
}
signed main() {
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
	Writer: 月雩·薇嫭
*/
