#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
using namespace std;
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int n, a[N], b[N], c[N];
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
	for(int i = 1; i <= n; i++) b[i] = read();
	for(int i = 1; i <= n; i++) c[i] = read();
	int cnt1 = 0, cnt2 = 0;
	for(int i = 1; i <= n; i++) {
		int nowj = 1, nowk = i, f = 1;
		for(int j = 1; j <= n; j++) {
			if(b[nowj] >= c[nowk]) {
				f = false;
				break;
			}
			nowj++;
			nowk++;
			if(nowk == n + 1) nowk = 1;
		}
		if(f) cnt1++;
	}
	for(int i = 1; i <= n; i++) {
		int nowi = 1, nowj = i, f = 1;
		for(int j = 1; j <= n; j++) {
			if(a[nowi] >= b[nowj]) {
				f = false;
				break;
			}
			nowi++;
			nowj++;
			if(nowj == n + 1) nowj = 1;
		}
		if(f) cnt2++;
	}
	cout << cnt1 * cnt2 * n << '\n';
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
