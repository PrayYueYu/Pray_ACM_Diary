#include<bits/stdc++.h>
#define int long long
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int n, a[N], f[N][6][6][6];
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
int calc(int x, int y) {
	if(!x || !y) return 0;
	return (y - x + 5) % 5;
}
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= n; i++) {
		for(int x = 0; x <= 5; x++) {
			for(int y = 0; y <= 5; y++) {
				for(int z = 0; z <= 5; z++) {
					f[i][x][y][z] = -INF;
				}
			}
		}
	}
	f[1][a[1]][0][0] = 0;
	f[1][0][a[1]][a[1]] = 0;
//	std::cout << calc(a[1], a[2]) << '\n';
	for(int i = 2; i <= n; i++) {
		for(int x = 0; x <= 5; x++) {
			f[i][x][a[i]][a[i]] = std::max(f[i][x][a[i]][a[i]], f[i - 1][x][0][0] + calc(x, a[i]));
		}
		for(int x = 0; x <= 5; x++) {
			for(int y = 0; y <= 5; y++) {
				for(int z = 0; z <= 5; z++) {
					f[i][a[i]][y][z] = std::max(f[i][a[i]][y][z], f[i - 1][x][y][z] + calc(x, a[i]) + calc(a[i], y) - calc(x, y));
					f[i][x][y][a[i]] = std::max(f[i][x][y][a[i]], f[i - 1][x][y][z] + calc(z, a[i]));
				}
			}
		}
	}
	int ans = -INF;
	for(int x = 0; x <= 5; x++) {
		for(int y = 0; y <= 5; y++) {
			for(int z = 0; z <= 5; z++) {
				ans = std::max(ans, f[n][x][y][z]);
			}
		}
	}
	std::cout << ans + n << '\n';
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
