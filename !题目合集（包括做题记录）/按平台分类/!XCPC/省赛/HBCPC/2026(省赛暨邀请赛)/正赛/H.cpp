#include<bits/stdc++.h>
#define int long long
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int n, q, sum[N][26];
std::string s;
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
	n = read(), q = read();
	std::cin >> s;
	s = " " + s;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= 25; j++) {
			sum[i][j] = sum[i - 1][j];
		}
		sum[i][s[i] - 'a']++;
	}
	for(int i = 1; i <= q; i++) {
		int l = read(), r = read();
		int ans = -1;
		for(int j = 0; j <= 25; j++) {
			ans = std::max(ans, sum[r][j] - sum[l - 1][j]);
		}
		std::cout << ans << '\n';
	}
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
