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
	std::cout << "I've becoming this, all I want to do, Is be more like me, and be less like you.";
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T = 1;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
