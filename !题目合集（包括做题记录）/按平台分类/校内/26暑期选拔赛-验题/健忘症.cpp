#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int a, b;
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
	std::cin >> a >> b;
	int ans = 0;
	if(b - a <= 10) {
		for(int i = a; i <= b; i++) ans = ans ^ i;
		std::cout << ans << '\n';
		return;
	}
	if(a & 1) ans ^= a, a++;
	if(!(b & 1)) ans ^= b, b--;
	if(((b - a + 1) / 2) & 1) ans ^= 1;
	std::cout << ans << '\n';
}
signed main() {
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
