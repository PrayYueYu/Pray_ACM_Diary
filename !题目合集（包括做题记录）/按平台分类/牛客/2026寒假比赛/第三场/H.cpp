#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;

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
	int xb = read(), yb = read();
	int xc = read(), yc = read();
	int c1 = 4 - (xb * yc - xc * yb);
	int c2 = -4 - (xb * yc - xc * yb);
	if(yb == yc) {
		double s = fabs((xb - xc) * yb);
		if(s == 4.0) std::cout << "0";
		else std::cout << "no answer";
	}
	else {
		double ans = (double)c1 / (double)(yb - yc);
		printf("%.10lf", ans);
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
