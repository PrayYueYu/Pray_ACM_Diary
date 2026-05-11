#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, fac[N], invfac[N];
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
		x = (x * x) % mod;
		y >>= 1;
	}
	return ans;
}
void pre() {
	fac[0] = 1;
	for(int i = 1; i <= 1000000; i++) {
		fac[i] = fac[i - 1] * i % mod;
	}
	invfac[1000000] = ksm(fac[1000000], mod - 2);
	for(int i = 999999; i >= 0; i--) {
		invfac[i] = invfac[i + 1] * (i + 1) % mod;
	}
}
void solve() {
	n = read();
	if(n == 1) {
		std::cout << 1 << '\n';
		return;
	}
	int nowlen = n, nexlen = n - n / 2;
	int ans = 1;
	while(true) {
		int ex = (nowlen - nexlen) * invfac[nowlen] % mod;
		ans = (ans + ex) % mod;
		if(nexlen == 1) break;
		nowlen = nexlen;
		nexlen = nexlen - nexlen / 2;
	}
	std::cout << ans << '\n';
}
signed main() {
	pre();
	int T = 1;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
4399
766735028
*/
