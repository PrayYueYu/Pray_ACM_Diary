#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int n, ans[300][300], d[20000];
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
void init() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			ans[i][j] = 0;
		}
	}
	for(int i = 1; i <= n * n; i++) d[i] = 0;
}
int query(int x, int y) {
	std::cout << "? " << x << ' ' << y << std::endl;
	int dx = read();
	return dx;
}
void GetAns() {
	std::cout << "!\n";
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			std::cout << ans[i][j] << ' ';
		}
		std::cout << '\n';
	}
	std::cout.flush();
}
void solve() {
	n = read();
	if(n == 1) {
		std::cout << "!\n";
		std::cout << 1 << std::endl;
		return;
	}
	int maxn = -1, maxid = 0;
	int l = 0, r = 0, a = 0, b = 0;
	for(int i = 1; i <= n * n; i++) {
		int dx = query(1, i);
		if(dx > maxn) {
			maxn = dx;
			maxid = i;
		}
	}
	l = maxid;
	maxn = -1;
	int xx = 0;
	for(int i = 1; i <= n * n; i++) {
		d[i] = query(l, i);
		if(d[i] > maxn) {
			maxn = d[i];
			r = i;
		}
		if(d[i] == 1) xx = i;
	}
	maxn = -1;
	for(int i = 1; i <= n * n; i++) {
		if(d[i] == n - 1) {
			int dx = query(xx, i);
			if(dx > maxn) {
				maxn = dx;
				a = i;
			}
		}
	}
	ans[1][1] = l, ans[n][n] = r;
	ans[1][n] = a, ans[n][1] = b;
	for(int i = 1; i <= n * n; i++) {
		int dx = query(a, i);
		int x = dx + d[i] - (n - 1);
		x /= 2;
		int y = d[i] - x;
		x++, y++;
		ans[x][y] = i;
	}
	GetAns();
}
signed main() {
	int T = read();
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*
------------------------------
	Writer: yueyuweihu
	Blog: prayyueyu.github.io
------------------------------
test:

*/
