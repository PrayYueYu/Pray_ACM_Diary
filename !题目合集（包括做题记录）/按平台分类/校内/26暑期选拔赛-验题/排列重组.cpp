#include<bits/stdc++.h>
#define int long long
const int N = 1e7 + 10, mod = 998244353, INF = 1e18;
int fac[N], invfac[N], n;
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
		y >>= 1;
		x = (x * x) % mod;
	}
	return ans;
}
void pre() {
	fac[0] = 1;
	for(int i = 1; i <= 10000000; i++) {
		fac[i] = fac[i - 1] * i % mod;
	}
	invfac[10000000] = ksm(fac[10000000], mod - 2);
	for(int i = 9999999; i >= 0; i--) {
		invfac[i] = invfac[i + 1] * (i + 1) % mod;
	}
}
int C(int x, int y) {
	if(x < y) return 0;
	int ans = fac[x];
	ans = ans * invfac[y] % mod;
	ans = ans * invfac[x - y] % mod;
	return ans;
}
void solve() {
	std::cin >> n;
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		int cx = C(n - i, i - 1);
		int now = cx * fac[i - 1] % mod;
		now = now * fac[n - i] % mod;
		sum = (sum + now) % mod;
	}
	std::cout << sum;
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

*/
