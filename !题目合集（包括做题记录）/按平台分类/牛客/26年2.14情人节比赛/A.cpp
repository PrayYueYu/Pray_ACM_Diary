#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, m, p[N], a[N];
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
struct S {
	double p, c, a;
	int id;
} s[N];
bool cmp(S x, S y) {
	return x.a > y.a;
}
void solve() {
	n = read(), m = read();
	if(n == 1) std::cout << -1;
	else {
		std::cout << n << '\n';
		for(int i = 1; i < n; i++) std::cout << 1 << ' ';
		std::cout << 4;
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
