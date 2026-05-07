#include<bits/stdc++.h>
const int N = 2e6 + 10, mod = 998244353, INF = 1e8;
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
void print(int x, int y) {
	if(x == 1 && y == 1) return;
	if(x == n && y == m) return;
	printf("%d %d\n", x, y);
}
void solve() {
	std::cin >> n >> m;
	if(n & 1) {
		std::cout << "YES\n";
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				if(i & 1) print(i, j);
				else print(i, m - j + 1);
			}
		}
	}
	else if(m & 1) {
		std::cout << "YES\n";
		for(int j = 1; j <= m; j++) {
			for(int i = 1; i <= n; i++) {
				if(j & 1) print(i, j);
				else print(n - i + 1, j);
			}
		}
	}
	else {
		std::cout << "NO";
		return;
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
