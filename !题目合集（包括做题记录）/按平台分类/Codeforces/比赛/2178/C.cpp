#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
using namespace std;
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int sum[N], a[N], n;
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
int calc(int l, int r) {
	int ans = sum[r] - sum[l - 1];
	return ans;
}
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		sum[i] = sum[i - 1] + a[i];
	}
	int ans = -calc(2, n);
	int now = a[1];
	for(int i = 2; i <= n; i++) {
		ans = max(ans, now - calc(i + 1, n));
		now += abs(a[i]);
	}
	cout << ans << '\n';
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
7
2
2 -3
4
1 4 3 4
4
-4 2 3 -6
5
-2 -3 4 10 -9
5
-12345678 -1000000000 -999999999 1000000000 -999999999
2
-7 1
5
7 -6 -1 -8 -8


3
8
4
15
2987654321
-1
29


*/
