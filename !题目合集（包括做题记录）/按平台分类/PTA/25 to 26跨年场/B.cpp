#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
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

void solve() {
	int a, b, c;
	std::cin >> a >> b >> c;
	int s;
	std::cin >> s;
	std::cout << s << std::endl;
	if(s < c) {
		std::cout << "mei jiang T_T";
	}
	else if(s < b) {
		std::cout << "san deng jiang";
	}
	else if(s < a) std::cout << "er deng jiang";
	else std::cout << "yi deng jiang";
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
