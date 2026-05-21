#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 1e9 + 7, INF = 1e18;
int f[1000], p[1000], m, a[100];
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
int getst(int x) {
	int ans = 0;
	for(int i = 32; i >= 0; i--) {
		if(x >> i & 1) {
			x -= p[i];
			ans = (ans + f[i] * ksm(10, x) % mod) % mod;
		}
	}
	return ans;
}
void solve() {
	m = read();
	for(int i = 0; i <= 9; i++) a[i] = read();
	if(m == 1 && a[0]) {
		std::cout << 0 << '\n';
		return;
	}
	int ans = 0, cnt = 0;
	for(int i = 1; i <= 9; i++) {
		if(a[i]) {
			a[i]--;
			ans = i;
			cnt = 1;
			break;
		}
	}
	for(int i = 0; i <= 9; i++) {
		if(cnt + a[i] <= m) {
			cnt += a[i];
			ans = ans * ksm(10, a[i]) % mod;
			int x = i * getst(a[i]) % mod;
			ans = (ans + x) % mod;
		}
		else {
			int t = m - cnt;
			ans = ans * ksm(10, t) % mod;
			int x = i * getst(t) % mod;
			ans = (ans + x) % mod;
			break;
		}
	}
	std::cout << ans << '\n';
}
signed main() {
	f[0] = 1, p[0] = 1;
	for(int i = 1; i <= 32; i++) {
		p[i] = p[i - 1] * 2;
		f[i] = f[i - 1] * ksm(10, p[i - 1]) + f[i - 1];
		f[i] %= mod;
	}
	int T = read();
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
