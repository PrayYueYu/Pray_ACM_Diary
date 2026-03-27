#include<bits/stdc++.h>
#define int long long
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int n, a[N], vis[3][N];
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
	for(int i = 1; i <= n; i++) {
		a[i] = read();
	}
	int ans1 = 0, ans2 = 0;
	for(int i = 1; i <= n; i += 2) ans2 += (n - i + 1);
	for(int i = 2; i <= n; i += 2) ans1 += (n - i + 1);
	int s = 0;
	for(int i = 1; i <= n; i++) {
		s = s ^ a[i];
		if(!s && !(i & 1)) ans1--, ans2++;
		ans1 -= vis[i & 1][s];
		ans2 += vis[i & 1][s];
		vis[i & 1][s]++;
	}
	s = 0;
	for(int i = 1; i <= n; i++) {
		s = s ^ a[i];
		vis[i & 1][s]--;
	}
	std::cout << ans1 << ' ' << ans2 << '\n';
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
