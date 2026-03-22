#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, a[N];
int read() {
//	int x = 0, f = 1;
//	char ch = getchar();
//	while(ch < '0' || ch > '9') {
//		if(ch == '-') f = -1;
//		ch = getchar();
//	}
//	while(ch >= '0' && ch <= '9') {
//		x = x * 10 + ch - '0';
//		ch = getchar();
//	}
//	return x * f;
	int x;
	std::cin >> x;
	return x;
}
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
	}
	std::sort(a + 1, a + n + 1);
	int ansx = 0, ansy = 0, resx = 1, resy = 1, now = 1;
	while(true) {
		if(now > n) break;
		for(int i = now; i <= std::min(n, now + resx - 1); i++) {
			ansx += a[i];
		}
		now = std::min(n, now + resx - 1) + 1; 
		for(int i = now; i <= std::min(n, now + resy - 1); i++) {
			ansy += a[i];
		}
		now = std::min(n, now + resx - 1) + 1;
		resx++, resy++;
	}
	std::cout << ansx << ' ' << ansy;
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T = 1;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
