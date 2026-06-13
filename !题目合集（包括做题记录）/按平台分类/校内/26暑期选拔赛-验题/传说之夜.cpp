#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, f[N][3], a[N], b[N];
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
	std::cin >> n;
	for(int i = 1; i <= n; i++) std::cin >> a[i];
	for(int i = 1; i <= n; i++) std::cin >> b[i];
	f[0][0] = f[0][1] = 0;
	for(int i = 1; i <= n; i++) {
		f[i][0] = std::min(b[i] - f[i - 1][1], f[i - 1][0] - a[i]);
		f[i][1] = std::max(b[i] - f[i - 1][0], f[i - 1][1] - a[i]);
	}
	std::cout << f[n][1] << '\n';
}
signed main() {
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
