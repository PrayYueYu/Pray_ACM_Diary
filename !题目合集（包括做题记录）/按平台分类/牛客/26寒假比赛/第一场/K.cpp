#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 1e9 + 7, INF = 1e18;
int n, a[N];
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
	n = read();
	if(n == 1) std::cout << "YES\n1\n";
	else if(n == 3) std::cout << "YES\n1 2 3\n";
	else std::cout << "NO\n";
}
signed main() {
	int T = read();
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
