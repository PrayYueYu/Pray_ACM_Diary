#include<bits/stdc++.h>
#define int long long
const int N = 1e5 + 10, mod = 998244353, INF = 1e18;
int n, a[2000];
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
bool check(int x) {
	if(x <= 1) return false;
	for(int i = 2; i <= sqrt(x); i++) {
		if(x % i == 0) return false;
	}
	return true;
}
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	std::cout << a[1];
	for(int i = 2; i <= n; i++) {
		if(!check(i)) {
			std::cout << ' ' << a[i];
		}
	}
	if(n <= 50 && n >= 10) {
		std::cout << ' ';
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
