#include<bits/stdc++.h>
#define int long long
const int N = 2e5 + 10, mod = 998244353, INF = 1e18;
int n, m;
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
	n = read(), m = read();
	std::vector<std::vector<int>> v;
	v.resize(n + 10, std::vector<int>(m + 10));
	int cnt0 = 0, cnt1 = 0;
	for(int i = 1; i <= n; i++) {
		std::string s = "";
		std::cin >> s;
		for(int j = 1; j <= m; j++) {
			v[i][j] = s[j - 1] - '0';
			if(v[i][j]) cnt1++;
			else cnt0++;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(v[i][j]) {
				if(cnt1 == 1) std::cout << "N";
				else std::cout << "Y";
			}
			else {
				if(cnt0 == 1) std::cout << "N";
				else std::cout << "Y";
			}
		}
		std::cout << '\n';
	}
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
