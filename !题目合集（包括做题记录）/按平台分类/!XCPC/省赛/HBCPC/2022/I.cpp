#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 1000000007, INF = 1e18;
int n, m, f[N][3];
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
void solve() {
	n = read(), m = read();
	f[1][0] = 0;
	f[1][1] = m;
	f[2][0] = m;
	f[2][1] = (m - 1) * m % mod;
	for(int i = 3; i <= n; i++) {
		f[i][0] = f[i - 1][1];
		f[i][1] = (f[i - 1][0] + f[i - 1][1]) * (m - 2);
		if(i == 3) f[i][1] += f[i - 1][0];
		f[i][0] %= mod;
		f[i][1] %= mod;
	}
	std::cout << (f[n][0] + f[n][1]) % mod << '\n';
}
signed main() {
	int T = 1;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
