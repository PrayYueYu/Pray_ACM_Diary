#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, q, s, st[N], t[N];
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
//std::map<int, int> st;
void solve() {
	n = read(), q = read(), s = read();
	st[1] = s;
	for(int i = 1; i <= n; i++) {
		t[i] = read();
		st[i + 1] = st[i] + t[i];
	}
	for(int i = 1; i <= q; i++) {
		int x = read(), y = read();
		std::cout << st[x] + y - 1 << '\n';
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

*/
