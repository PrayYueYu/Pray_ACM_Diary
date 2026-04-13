#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int sum[N], a[N], n, m, k;
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
	n = read(), m = read(), k = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		a[i + n] = a[i];
		sum[i] = sum[i + n] = 0;
	}
	for(int i = 1; i <= 2 * n; i++) {
		sum[i] = a[i];
		if(i >= m) sum[i] += sum[i - m];
	}
	int ans = -INF;
	int t = n / m;
	if(k <= n % m) t++;
	for(int i = 1; i <= 2 * n; i++) {
		if(i >= t * m) {
			ans = std::max(ans, sum[i] - sum[i - t * m]);
		}
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
