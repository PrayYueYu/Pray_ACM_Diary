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
	int sum = 0, ans = INF;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		if(i >= 2) sum = sum + abs(a[i] - a[i - 1]);
	}
	ans = std::min({ans, sum - abs(a[1] - a[2]), sum - abs(a[n] - a[n - 1])});
	for(int i = 2; i < n; i++) {
		ans = std::min(ans, sum - abs(a[i] - a[i - 1]) - abs(a[i] - a[i + 1]) + abs(a[i + 1] - a[i - 1]));
	}
	std::cout << ans << std::endl;
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
