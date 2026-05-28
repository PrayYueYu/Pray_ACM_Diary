#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, m;
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
	n = read(), m = read();
	int maxn = -1, id = 0;
	for(int i = 1; i <= n; i++) {
		int a = read(), b = read();
		if(a * 12 <= b) {
			if(m / a > maxn) {
				maxn = m / a;
				id = i;
			}
		}
		else {
			int mx = m;
			int t = mx - (mx / b) * b;
			if((mx / b) * 12 + t / a > maxn) {
				maxn = (mx / b) * 12 + t / a;
				id = i;
			}
		}
	}
	std::cout << maxn << ' ' << id;
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
