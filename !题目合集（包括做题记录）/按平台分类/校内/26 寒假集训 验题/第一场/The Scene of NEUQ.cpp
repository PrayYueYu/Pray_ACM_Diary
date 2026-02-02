#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int n, p3[100];
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
int getsum(int l, int r) {
	if(l > r) return 0;
	int ans = 0;
	for(int i = l; i <= r; i++) {
		ans += p3[i];
	}
	return ans;
}
void solve() {
	n = read();
	int ans = INF;
	for(int i = 0; i <= 34; i++) {
		int now = getsum(0, i - 1) * 2 + p3[i] - 1;
		if(now > n) break;
		int x = i;
		now = getsum(0, i - 1);
		for(int j = i; j >= 0; j--) {
			int t = (n - getsum(1, j - 1) - now) / p3[j];
			x += t;
			now += t * p3[j];
		}
		ans = std::min(ans, x);
	}
	std::cout << ans << '\n';
}
signed main() {
	int T = 1;
	p3[0] = 1;
	for(int i = 1; i <= 34; i++) p3[i] = p3[i - 1] * 3ll;
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
