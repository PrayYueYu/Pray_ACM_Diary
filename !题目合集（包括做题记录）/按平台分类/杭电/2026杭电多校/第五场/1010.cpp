#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int p[200], t[200], n, q, v[200][200];
void init() {
	for(int i = 0; i <= 100; i++) {
		for(int j = 0; j <= 100; j++) v[i][j] = 0;
		p[i] = 0;
		t[i] = 0;
	}
}
void insert(int s) {
	for(int i = 100; i >= 0; i--) {
		if(!t[i]) continue;
		if(!v[i][i]) {
			p[i] = s;
			for(int j = 100; j >= 0; j--) {
				v[i][j] ^= t[j];
			}
			return;
		}
		s = s ^ p[i];
		for(int j = 100; j >= 0; j--) {
			t[j] ^= v[i][j];
		}
	}
}
int query() {
	int ans = 0;
	for(int i = 100; i >= 0; i--) {
		if(!t[i]) continue;
		if(!v[i][i]) return -1;
		ans ^= p[i];
		for(int j = 100; j >= 0; j--) t[j] ^= v[i][j];
	}
	return ans;
}
void solve() {
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		int c, s;
		std::cin >> c >> s;
		for(int j = 0; j <= 100; j++) t[j] = false;
		for(int j = 1; j <= c; j++) {
			int x;
			std::cin >> x;
			t[x] ^= 1;
		}
		insert(s);
	}
	std::cin >> q;
	for(int i = 1; i <= q; i++) {
		int c;
		std::cin >> c;
		for(int j = 0; j <= 100; j++) t[j] = false;
		for(int j = 1; j <= c; j++) {
			int x;
			std::cin >> x;
			t[x] ^= 1;
		}
		std::cout << query() << '\n';
	}
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
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
