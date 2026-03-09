#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, m;
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
	int f = 0;
	char c[10]; c[0] = '\\', c[1] = '/';
	n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		f = (i & 1);
		for(int j = 1; j <= m; j++) {
			std::cout << c[f];
			f ^= 1;
		}
		std::cout << '\n';
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
