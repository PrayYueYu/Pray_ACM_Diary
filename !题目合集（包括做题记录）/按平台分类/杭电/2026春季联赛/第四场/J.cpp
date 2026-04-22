#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, m;
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
	n = read(), m = read();
	int minn = -1, f = 1;
	for(int i = 1; i <= n; i++) {
		int minnx = INF;
		for(int j = 1; j <= m; j++) {
			int x = read();
			if(x < minnx && x > minn) {
				minnx = x;
			}
		}
		if(minnx == INF) {
			f = false;
		}
		else minn = minnx;
	}
	if(f) std::cout << "YES\n";
	else std::cout << "NO\n";
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

*/
