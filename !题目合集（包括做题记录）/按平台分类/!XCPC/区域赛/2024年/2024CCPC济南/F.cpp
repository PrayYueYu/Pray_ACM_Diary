#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 100, M = 998244353;
int n, fac[N], invfac[N], m, cnt;
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
int ksm(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = (ans * x) % M;
		x = (x * x) % M;
		y >>= 1;
	}
	return ans;
}
void pre() {
	fac[0] = 1;
	int Nx = N - 10;
	for(int i = 1; i <= Nx; i++) {
		fac[i] = (fac[i - 1] * i) % M;
	}
	invfac[Nx] = ksm(fac[Nx], M - 2);
	for(int i = Nx - 1; i >= 0; i--) {
		invfac[i] = (invfac[i + 1] * (i + 1)) % M;
	}
}
int C(int x, int y) {
	if(x < 0 || y < 0) return 0;
	if(x < y) return 0;
	int ans = fac[x];
	ans = (ans * invfac[y]) % M;
	ans = (ans * invfac[x - y]) % M;
	return ans;
}
inline int calc(int x, int y) {
	if(y <= 1) return 0;
	if(x <= 2) return 0;
	if(x <= y) return 0;
	int ans = 0;
	for(register int i = 2; i <= x; i++) {
		int num = (x / i) - 1;
		if(x - i < y - 1) break;
		ans = (ans + calc(x / i, y - 1)) % M;
		int s = (C(x - i, y - 1) - C(num, y - 1) + M) % M;
		s = (s * y) % M;
		ans = (ans + s) % M;
	}
	return ans;
}
inline void solve() {
	n = read(), m = read();
	if(m == 1) {
		cout << 0 << endl;
		return;
	}
	int ans = 0;
	
	for(register int i = 1; i <= n; i++) {
		int num = n / i - 1;
		ans = (ans + calc(n / i, m - 1)) % M;
		
		int s = (C(n - i, m - 1) - C(num, m - 1) + M) % M;
		s = (s * m) % M;
		ans = (ans + s) % M;
	}
	cout << ans << endl;
}
signed main() {
	pre();
	int T = 1;
	while(T--) {
		solve();
	//	init();
	}
	return 0;
}
