#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int dx[20] = {0, 0, 0, 0, 0, 1, 1, 1, -1, -1, -1, 2, -2};
int dy[20] = {-2, -1, 0, 1, 2, -1, 0, 1, -1, 0, 1, 0, 0};
int a[600][600], cnt[600][600], n, m, q;
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
bool check(int x, int y) {
	if(x > n || y > m || x < 1 || y < 1) return false;
	return true;
}
int getsum(int x, int y) {
	int sum = 0;
	for(int i = 0; i <= 12; i++) {
		int sx = x + dx[i];
		int sy = y + dy[i];
		if(!check(sx, sy)) continue;
		sum += a[sx][sy];
	}
	return sum;
}
void solve() {
	n = read(), m = read(), q = read();
	int maxn = -INF, maxi = 0, maxj = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			a[i][j] = read();
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			int num = getsum(i, j);
			cnt[i][j] = num;
			if(num > maxn) {
				maxn = num;
				maxi = i, maxj = j;
			}
		}
	}
	for(int i = 1; i <= q; i++) {
		int x = read(), y = read(), z = read();
		a[x][y] += z;
		for(int j = 0; j <= 12; j++) {
			int sx = x + dx[j];
			int sy = y + dy[j];
			if(!check(sx, sy)) continue;
			cnt[sx][sy] += z;
			if(cnt[sx][sy] > maxn) {
				maxn = cnt[sx][sy];
				maxi = sx, maxj = sy;
			}
		}
		std::cout << maxi << ' ' << maxj << '\n';
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
