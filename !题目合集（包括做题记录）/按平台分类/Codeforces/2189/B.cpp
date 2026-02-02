#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int n;
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
	int a, b, c, d;
} s[N];
bool cmp(S x, S y) {
	return x.d > y.d;
}
void solve() {
	n = read(); int x = read(), sum = 0;
	for(int i = 1; i <= n; i++) {
		s[i].a = read();
		s[i].b = read();
		s[i].c = read();
		s[i].d = s[i].b * s[i].a - s[i].c;
		sum += s[i].a * (s[i].b - 1);
	}
	if(sum >= x) {
		std::cout << 0 << '\n';
		return;
	}
	std::sort(s + 1, s + n + 1, cmp);
	if(s[1].d <= 0) {
		std::cout << -1 << '\n';
		return;
	}
	int ans = (x - sum) / s[1].d;
	for(int i = ans - 3; i <= ans + 3; i++) {
		if(i * s[1].d >= x - sum) {
			std::cout << i << '\n';
			return;
		}
	}
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
