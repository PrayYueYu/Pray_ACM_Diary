#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, fac[N], invfac[N], a[N], x;
std::map<int, int> l, r;
int ksm(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = ans * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return ans;
}
void init() {
	fac[0] = 1;
	for(int i = 1; i <= 2000000; i++) {
		fac[i] = fac[i - 1] * i % mod;
	}
	invfac[2000000] = ksm(fac[2000000], mod - 2);
	for(int i = 1999999; i >= 0; i--) {
		invfac[i] = invfac[i + 1] * (i + 1) % mod;
	}
}
int C(int x, int y) {
	if(y > x) return 0;
	int ans = fac[x];
	ans = ans * invfac[y] % mod;
	ans = ans * invfac[x - y] % mod;
	return ans;
}
void solve() {
	std::cin >> n >> x;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	std::sort(a + 1, a + n + 1);
	int s = 1, t = 0;
	a[n + 1] = -1;
	for(int i = 1; i <= n; i++) {
		if(a[i] != a[i + 1]) {
			t = i;
			l[a[i]] = s;
			r[a[i]] = t;
			s = i + 1;
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int L = l[2 * x - a[i]], R = r[2 * x - a[i]];
		if(!L) continue;
		if(L <= i && i <= R) {
			if(i < R) {
				L = i + 1;
				ans = ((ans + C(n + i - L, i) - C(n + i - R - 1, i)) % mod + mod) % mod;
			}
			ans = (ans + C(n - 1, i - 1)) % mod;
		}
		else {
			if(R < i) break;
			ans = ((ans + C(n + i - L, i) - C(n + i - R - 1, i)) % mod + mod) % mod;
		}
	}
	std::cout << ans << '\n';
}
signed main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(0);
//	std::cout.tie(0);
	init();
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
