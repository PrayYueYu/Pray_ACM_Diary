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
	std::string s = "";
	std::cin >> s;
	int sz = s.size(), f1 = 0, f2 = 0;
	for(int i = 0; i < sz; i++) {
		if(s[i] == '1') f2 = i;
		if(s[i] == '9') f1 = i;
	}
	if(f1 && f2) {
		std::cout << f1 + 1 << ' ' << f2 + 1;
	}
	else std::cout << -1;
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
