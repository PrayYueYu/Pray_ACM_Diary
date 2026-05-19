#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, p[100];
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
	if(n & 1) {
		printf("%.2lf\n", (double)p[n / 2]);
		return;
	}
	else {
		n--;
		double ans = (double)p[n / 2] * sqrt(2);
		printf("%.2lf\n", ans);
	}
}
signed main() {
	p[0] = 1;
	for(int i = 1; i <= 50; i++) p[i] = p[i - 1] * 2;
	int T = read();
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
