#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int vis[10][10], n;
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
	for(int i = 1; i <= 6; i++) {
		int x = read();
		vis[i][x] = true;
	}
	n = read();
	for(int i = 1; i <= 6; i++) {
		int now = 6;
		for(int j = 1; j <= n; j++) {
			while(true) {
				if(vis[i][now]) now--;
				else break;
			}
			vis[i][now] = true;
		}
		std::cout << now;
		if(i != 6) std::cout << ' ';
	}
}
signed main() {
	int T = 1;
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
