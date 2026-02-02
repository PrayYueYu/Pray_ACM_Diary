#include<bits/stdc++.h>
//#define getchar getchar_unlocked
#define int long long
using namespace std;
const int N = 1e6 + 10, M = 1e9 + 7, INF = 1e18;
int f[N], a[N], n, c;
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x * f;
}
void solve() {
	n = read(), c = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
	}
	f[n] = a[n] - c;
	f[n - 1] = a[n - 1] - c;
	f[n - 2] = max(a[n - 2] - c, f[n] + a[n - 2]);
	int maxn = f[n];
	for(int i = n - 3; i >= 1; i--) {
		f[i] = max({a[i] - c, f[i + 2] + a[i], maxn + a[i] - c});
		maxn = max(maxn, f[i + 2]);
	}
	int ans = -INF;
	for(int i = 1; i <= n; i++) ans = max(ans, f[i]);
	cout << ans;
}
signed main() {
	int T = 1;
	while(T--) solve();
	return 0;
}
/*
	Writer: yueyu_weihu
	Blog: prayyueyu.github.io
*/
