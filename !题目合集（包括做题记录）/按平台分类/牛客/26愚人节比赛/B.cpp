#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 1e8 + 7, INF = 1e18;

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
	int n = read();
	std::string s;
	std::cin >> s;
	int f = true;
	for(int i = 0; i < n; i++) {
		if(s[i] != s[0]) {
			f = false;
			break;
		}
	}
	if(!f) {
		std::cout << "NO";
		return;
	}
	int ans = 1;
	for(int i = 1; i <= n; i++) {
		ans = (ans * i) % mod;
	}
	std::cout << ans;
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
NO
*/
