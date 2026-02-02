#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;

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
int lowbit(int x) {
	return x & (-x);
}
void solve() {
	int n = read();
	if(lowbit(n) == n) {
		std::cout << -1 << '\n';
		return;
	}
	if(n & 1) std::cout << n - 1 << ' ';
	else std::cout << (lowbit(n) ^ 1) << ' ';
	for(int i = 2; i < n; i++) {
		if(!(n & 1) && i == lowbit(n))
			std::cout << n << ' ';
		else std::cout << (i ^ 1) << ' ';
	}
	std::cout << 1 << '\n';
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
