#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 1e9 + 7, INF = 1e18; 
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
	int maxn = -INF;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		maxn = std::max(maxn, a[i]);
	}
	if(n == 1) {
		std::cout << a[1] << '\n';
		return;
	}
	std::cout << maxn * (n - 2) + a[1] + a[n] << '\n';
}
signed main() {
	int T = read();
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
