#include<bits/stdc++.h>
//#define getchar getchar_unlocked
#define int long long
using namespace std;
const int N = 1e6 + 10, M = 1e9 + 7;
int a[N], n, m, maxn[N];
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
	n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		maxn[i] = -1;
	}
	int ans = 0;
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			int x = read();
			maxn[j] = max(maxn[j], x);
		}
	}
	for(int i = 1; i <= n; i++) {
		if(maxn[i] > a[i]) ans += maxn[i] - a[i];
	}
	cout << ans << '\n';
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
