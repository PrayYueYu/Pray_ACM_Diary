#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, inv6;
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
	std::cin >> n;
	if(n == 1) {
		int a;
		std::cin >> a;
		std::cout << a << '\n';
		return;
	}
	if(n == 2) {
		int a, b;
		std::cin >> a >> b;
		std::cout << (a + b) % mod << '\n';
		return;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int a = read();
		int x = n + 3;
		if(i == 1 || i == n) x = n + 4;
		int now = x * a % mod * inv6 % mod;
		ans = (ans + now) % mod;
	}
	std::cout << ans << '\n';
}
signed main() {
	inv6 = ksm(6, mod - 2);
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
	Writer: ÔÂö§Ş±‹¬ 
*/
