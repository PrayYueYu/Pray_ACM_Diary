#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int n, a[N];
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
	n = read();
	int ans = INF;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		ans = std::min(ans, a[i]);
	}
	int minn = ans;
	ans = INF;
	for(int i = 1; i <= n; i++) {
		if(a[i] == minn) continue;
		ans = std::min(ans, a[i] - minn);
	}
	std::cout << std::max(ans, minn) << std::endl;
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
