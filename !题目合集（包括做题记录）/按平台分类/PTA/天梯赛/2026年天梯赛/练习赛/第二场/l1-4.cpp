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
	int a = read(), b = read(), cnta = 0, cntb = 0;
	for(int i = 1; i <= 3; i++) {
		int f = read();
		if(!f) cnta++;
		else cntb++;
	}
	if((a > b && cnta)|| (a < b && cnta == 3)) {
		std::cout << "The winner is a: " << a << " + " << cnta;
	}
	else std::cout << "The winner is b: " << b << " + " << cntb;
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
