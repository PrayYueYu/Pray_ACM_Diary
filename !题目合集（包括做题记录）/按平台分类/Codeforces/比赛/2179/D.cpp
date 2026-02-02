#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int vis[N], n;
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
	std::vector<int> ans;
	for(int i = n; i >= 1; i--) {
		int now = (1 << i) - 1;
		int p = (1 << (i + 1));
		while(true) {
			if(now > (1 << n)) break;
			if(vis[now]) {
				now += p;
				continue;
			}
			vis[now] = true;
			ans.push_back(now);
			now += p;
		}
	}
	for(int i = 0; i < (1 << n); i++) {
		if(!(i & 1)) ans.push_back(i);
	}
	for(int i = 0; i < (1 << n); i++) {
		std::cout << ans[i] << ' ';
	}
	std::cout << '\n';
	for(int i = 0; i < (1 << n); i++) {
		vis[i] = false;
	}
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
