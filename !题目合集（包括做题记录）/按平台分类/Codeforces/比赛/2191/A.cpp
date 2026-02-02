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
	int a, c;
} s[N];
bool cmp(S x, S y) {
	return x.a < y.a;
}
void solve() {
	n = read();
	int f = 0;
	for(int i = 1; i <= n; i++) {
		s[i].a = read();
		s[i].c = f;
		f = 1 - f;
	}
	std::sort(s + 1, s + n + 1, cmp);
	for(int i = 2; i <= n; i++) {
//		std::cout << s[1].a << ' ' << s[1].c << '\n';
		if(s[i].c == s[i - 1].c) {
			std::cout << "NO\n";
			return;
		}
	}
	std::cout << "YES\n";
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
