#include<bits/stdc++.h>
#define int long long
const int N = 1e5 + 10, mod = 998244353, INF = 1e18;

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
	int x = read(), y = read();
	std::cout << std::max({0ll, x, y}) << ' ';
	int z = std::max(0ll, x + y);
	std::cout << z << '\n';
	if(x < 0 && y < 0) std::cout << "-_-";
	else if(x > 0 && y > 0) std::cout << "^_^";
	else std::cout << "T_T";
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
