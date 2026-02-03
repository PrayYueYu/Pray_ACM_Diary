#include<bits/stdc++.h>
#define int long long
const int N = 2e5 + 10, mod = 998244353, INF = 1e18;
int n, a[N], fac[N], b[N], d[N];
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
void pre() {
	fac[0] = 1;
	for(int i = 1; i <= N - 10; i++) {
		fac[i] = (fac[i - 1] * i) % mod;
	}
}
void solve() {
	n = read();
	int minn = INF;
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= n; i++) {
		b[i] = read();
		minn = std::min(minn, b[i]);
	}
	int cnt1 = 0, cnt2 = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] > minn) cnt1++;
		else cnt2++;
	}
	std::cout << (fac[cnt1] * fac[cnt2]) % mod << '\n';
}
signed main() {
	pre();
	int T = read();
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
