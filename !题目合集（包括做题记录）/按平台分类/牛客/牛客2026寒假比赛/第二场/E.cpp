#include<bits/stdc++.h>
#define int long long
const int N = 2e3 + 10, mod = 998244353, INF = 1e18;
int n, a[N][N];
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
	int f;
	if(n & 1) f = 0;
	else f = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= i; j++) {
			a[i][j] = f;
			a[j][i] = f;
		}
		f = 1 - f;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			std::cout << a[i][j];
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
