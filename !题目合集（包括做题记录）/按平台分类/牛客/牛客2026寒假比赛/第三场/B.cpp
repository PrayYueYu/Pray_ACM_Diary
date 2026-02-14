#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, a[N];
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
	if(n <= 10) {
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				if(std::__gcd(a[i], a[j]) != 1) {
					std::cout << a[i] << ' ' << a[j] << '\n';
					return;
				}
			}
		}
		std::cout << -1 << '\n';
		return;
	}
	int f = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] % 2 == 0) {
			if(!f) {
				f = a[i];
				continue;
			}
			std::cout << f << ' ' << a[i] << '\n';
			return;
		}
	}
	std::cout << -1 << '\n';
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
