#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int n, h, lx, a[N], vis[200][200];
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
	n = read(), h = read(), lx = read();
	if(h > lx) std::swap(h, lx);
	for(int i = 1; i <= n; i++) a[i] = read();
	std::sort(a + 1, a + n + 1);
	int x = n;
	for(int i = n; i >= 1; i--) {
		if(a[i] <= lx) {
			x = i;
			break;
		}
	}
	n = x;
	int l = 1, r = n, ans = 0;
	while(true) {
		if(l >= r) break;
		if(a[l] > h) break;
		l++, r--;
		ans++;
	}
	std::cout << ans << '\n';
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
------------------------------
	Writer: yueyuweihu
	Blog: prayyueyu.github.io
------------------------------
test:

*/
