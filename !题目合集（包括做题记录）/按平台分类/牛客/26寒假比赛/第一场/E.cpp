#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 1e9 + 7, INF = 1e18; 
int a[N], n;
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
	n = read(); n++;
	a[n] = read();
	int ans = -INF;
	for(int i = 1; i < n; i++) a[i] = read();
	for(int i = 1; i <= n; i++) {
		int ne = i + 1;
		if(ne > n) ne = 1;
		 ans = std::max(ans, a[i] + a[ne]);
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
