#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int s[N], n, m, k;
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
bool check(int mid) {
	for(int l = 1; l <= n; l++) {
		int r = l + mid - 1;
		if(r > n) break;
		if(l <= k && k <= r) {
			int s1 = k - l, s2 = r - k, cnt = 0;
//			std::cout << s1 << ' ' << s2 << '\n';
			if(s1 > s2) cnt = s[s1] + s2;
			else cnt = s[s2] + s1;
			if(cnt <= m) return true;
		}
	}
	return false;
}
void solve() {
	n = read(), m = read(), k = read();
	int l = 1, r = std::min(n, m + 1ll);
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	std::cout << l << '\n';
}
signed main() {
	for(int i = 1; i <= 1e5; i++) {
		s[i] = 2 * i - 1;
	}
	int T = read();
	while(T--) {
		solve();
//		init();
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
