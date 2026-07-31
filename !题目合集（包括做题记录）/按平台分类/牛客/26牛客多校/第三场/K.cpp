#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, x[N], y[N];
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
int cx(int x1, int y1, int x2, int y2) {
	return x1 * y2 - y1 * x2;
}
void solve() {
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		std::cin >> x[i] >> y[i];
		if(i >= 3) {
			int t = cx(x[i - 2] - x[i - 1], y[i - 2] - y[i - 1], x[i] - x[i - 1], y[i] - y[i - 1]);
			if(t == 0) std::cout << "STRAIGHT";
			else if(t < 0) std::cout << "LEFT";
			else std::cout << "RIGHT";
		}
		if(i != n) std::cout << ' ';
	}
	std::cout << '\n';
}
signed main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(0);
//	std::cout.tie(0);
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
----------------------
	Writer: ÔÂö§Þ±‹¬ | 
----------------------
*/
