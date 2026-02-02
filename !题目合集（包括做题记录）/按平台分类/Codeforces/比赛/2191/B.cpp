#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int n, a[N], cnt[N];
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
	for(int i = 1; i <= n; i++) cnt[a[i]]--;
}
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		cnt[a[i]]++;
	}
	if(cnt[0] == 0) {
		std::cout << "NO\n";
		return;
	}
	if(cnt[0] == 1) {
		std::cout << "YES\n";
		return;
	}
	if(cnt[1] == 0) {
		std::cout << "NO\n";
		return;
	}
	std::cout << "YES\n";
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
