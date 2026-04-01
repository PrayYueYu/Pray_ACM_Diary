#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, q, p[100];
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
	for(int i = 1; i <= q; i++) {
		int x = read();
		int l = 0;
		for(int j = 60; j >= 0; j--) {
			if(x >= p[j]) {
				l = p[j];
				break;
			}
		}
		int r = std::min(l * 2 - 1, n);
		std::cout << r - l + 1 << '\n';
	}
}
signed main() {
	p[0] = 1;
	for(int i = 1; i <= 60; i++) p[i] = p[i - 1] * 2;
	int T = read(); 
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
1
1000000000000000000 100
1000000000000000000
*/
