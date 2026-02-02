#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
using namespace std;
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;

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
	int sc, id;
	string name;
} s[N];
bool cmp(S x, S y) {
	if(x.sc == y.sc) return x.id < y.id;
	return x.sc > y.sc;
}
void solve() {
	int n = read(), p = read();
	for(int i = 1; i <= n; i++) {
		std::cin >> s[i].name >> s[i].sc;
		s[i].id = i;
	}
	sort(s + 1, s + n + 1, cmp);
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(s[i].sc >= p) cnt++;
	}
	std::cout << cnt << std::endl << s[1].name;
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
------------------------------
	Writer: yueyuweihu
	Blog: prayyueyu.github.io
------------------------------
test:

*/
