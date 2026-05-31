#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int ans, a[N], n;
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
	for(int i = 1; i <= n; i++) a[i] = read();
	int L = 0, R = 0, ans = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] <= R && a[i] >= L) {
			R = a[i] + 1;
		}
		else L = R = a[i] + 1, ans++;
	}
	std::cout << ans << '\n';
}
signed main() {
//	freopen("19.in", "r", stdin);
	int T; std::cin >> T;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
