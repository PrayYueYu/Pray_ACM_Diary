#include<bits/stdc++.h>
#define int unsigned long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int tr[N][2][2], n, m, a[N], b[N], suma[N];
void init() {
	for(int i = 0; i <= n + 1; i++) {
		for(int j = 0; j <= 1; j++) {
			for(int k = 0; k <= 1; k++) {
				tr[i][j][k] = 0;
			}
		}
		suma[i] = 0;
	}
}
int lowbit(int x) {
	return x & (-x);
}
int query(int x, int p1, int p2) {
	int ans = 0;
	while(x) {
		ans += tr[x][p1][p2];
		x -= lowbit(x);
	}
	return ans;
}
void add(int x, int y, int p1, int p2) {
	while(x <= n) {
		tr[x][p1][p2] += y;
		x += lowbit(x);
	}
}
void addx(int l, int r, int x, int p) {
	add(l, x, p, 0); add(r + 1, -x, p, 0);
	add(l, x * l, p, 1); add(r + 1, -x * (r + 1), p, 1);
}
int queryx(int l, int r, int p) {
	int s1 = (r + 1) * query(r, p, 0) - query(r, p, 1);
	int s2 = l * query(l - 1, p, 0) - query(l - 1, p, 1);
	return s1 - s2;
}
void solve() {
	std::cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i] >> b[i];
		addx(i, i, b[i], 0);
		suma[i] = suma[i - 1] + a[i];
	}
	for(int i = 1; i <= m; i++) {
		int op; std::cin >> op;
		if(op == 1) {
			int l, r, x;
			std::cin >> l >> r >> x;
			addx(l, r, x, 0);
			addx(l, r, i * x, 1);
		}
		else {
			int l, r;
			std::cin >> l >> r;
			int s1 = suma[r] - suma[l - 1] + i * queryx(l, r, 0);
			int s2 = queryx(l, r, 1);
			std::cout << s1 - s2 << '\n';
		}
	}
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*
----------------------
	Writer: ÔÂö§Þ±‹¬ | 
----------------------
*/
