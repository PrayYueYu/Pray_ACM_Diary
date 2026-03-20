#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n;
double c[N], f[N], p[N];
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
	n = read();
	for(int i = 1; i <= n; i++) {
		c[i] = read(), p[i] = read();
	}
	f[n] = c[n];
	for(int i = n - 1; i >=   1; i--) {
		f[i] = std::max(f[i + 1], f[i + 1] * (1.0 - p[i] / 100.0) + c[i]);
	}
	printf("%.10lf\n", f[1]);
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
