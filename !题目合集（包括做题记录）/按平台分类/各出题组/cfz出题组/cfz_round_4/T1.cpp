#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, p[N], a[N], m;
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
	n = read(), m = read();
	for(int i = 1; i <= m; i++) {
		p[i] = read(), a[i] = read();
	}
	if(m <= 1) {
		std::cout << "Yes\n";
		return;
	}
	int k = (a[2] - a[1]) / (p[2] - p[1]);
	if((a[2] - a[1]) % (p[2] - p[1]) != 0) {
		std::cout << "No\n";
		return;
	}
	for(int i = 3; i <= m; i++) {
		if((a[i] - a[1]) % (p[i] - p[1]) != 0) {
			std::cout << "No\n";
			return;
		}
		if((a[i] - a[1]) / (p[i] - p[1]) != k) {
			std::cout << "No\n";
			return;
		}
	}
	std::cout << "Yes\n";
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
