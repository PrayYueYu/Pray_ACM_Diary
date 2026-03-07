#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int a[N], f[N], b[N], n;
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
		a[i] = read();
		f[i] = a[i];
	}
	for(int i = 1; i <= n; i++) b[i] = read();
	for(int k = 1; k <= n; k++) {
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			f[i] = std::min(f[i], a[i + k - 1]);
			if(f[i] >= b[k]) ans = 1;
		}
		std::cout << ans;
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
