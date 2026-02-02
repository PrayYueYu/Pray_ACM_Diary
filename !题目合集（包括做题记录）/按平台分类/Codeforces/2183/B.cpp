#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int n, k, a[N], cnt[N];
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
	n = read(), k = read(); k--;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		cnt[a[i]]++;
	}
	int ans = n + 1;
	for(int i = 0; i <= n; i++) {
		if(cnt[i] && k) {
			k--;
			continue;
		}
		else {
			ans = i;
			break;
		}
	}
	std::cout << ans << '\n';
	for(int i = 1; i <= n; i++) cnt[a[i]] = 0;
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
