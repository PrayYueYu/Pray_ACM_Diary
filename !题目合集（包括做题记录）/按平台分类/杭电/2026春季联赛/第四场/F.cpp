#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, s;
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
	n = read(), s = read();
	int f = true, cnt = 0, fx = false;
	for(int i = 1; i <= n; i++) {
		int x = read();
		if(x == s) fx = true;
		if(!x) cnt++;
		if(x != s && x) f = false;
	}
	if(!s && cnt == n) std::cout << "YES\n";
	else if(!s && cnt != n) std::cout << "NO\n";
	else if(!f || !fx) std::cout << "NO\n";
	else std::cout << "YES\n";
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

*/
