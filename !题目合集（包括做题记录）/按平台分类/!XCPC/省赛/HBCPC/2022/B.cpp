#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 1e9 + 7, INF = 1e18;
int n;
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
		if(y & 1) ans = (ans * x) % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return ans;
}
void solve() {
	n = read();
	if(n <= 5) {
		if(n == 1) std::cout << 1 << '\n';
		if(n == 2) std::cout << 3 << '\n';
		if(n == 3) std::cout << 5 << '\n';
		if(n == 4) std::cout << 8 << '\n';
		if(n == 5) std::cout << 11 << '\n';
		return;
	}
	int ans = 0, inv2 = ksm(2, mod - 2), inv3 = ksm(3, mod - 2);
	int l = 2, r = 1000000;
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if((2 + mid) * (mid - 1) + 1 <= n) l = mid;
		else r = mid - 1;
	}
	int x = l;
	int s1 = 2 * x * (x + 1) % mod * (2 * x + 1) % mod;
//	std::cout << s1 << ' ';
	s1 = s1 * inv3 % mod;
	int s2 = 3 * (x + 1) * x % mod * inv2 % mod;
//	std::cout << s1 << ' ' << s2 << '\n';
	ans = (s1 - s2 + mod) % mod;
	
	int cnt = n - 1 - (2 + x) * (x - 1);
	if(cnt <= x + 1) {
		ans += cnt * (2 * x);
		ans %= mod;
	} 
	else {
		ans += (x + 1) * 2 * x;
		ans += (cnt - (x + 1)) * (2 * x + 1);
		ans %= mod;
	}
	std::cout << ans << '\n';
}
signed main() {
	int T = read();
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
