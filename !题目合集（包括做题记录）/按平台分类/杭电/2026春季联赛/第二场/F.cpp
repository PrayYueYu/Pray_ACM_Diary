#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, a[N], vis[N];
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
	for(int i = 1; i <= n; i++) a[i] = read();
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] <= n && !vis[a[i]]) vis[a[i]] = true, ans++;
	}
	for(int i = 1; i <= n; i++) {
		if(a[i] <= n) vis[a[i]] = false;
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
/*

*/
