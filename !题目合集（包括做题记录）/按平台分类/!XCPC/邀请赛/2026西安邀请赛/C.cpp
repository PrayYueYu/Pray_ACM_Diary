#include<bits/stdc++.h>
#define int long long
const int N = 5e3 + 10, mod = 998244353, INF = 1e18;
int n, f[N][N][3];
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
	std::string s;
	std::cin >> s;
	s = " " + s;
	for(int i = 0; i <= n + 2; i++) {
		for(int j = 0; j <= n + 2; j++) {
			if(i <= j) f[i][j][0] = f[i][j][1] = f[i][j][2] = -INF;
			else f[i][j][0] = f[i][j][1] = f[i][j][2] = -INF;
			if(j > i) {
				if(s[j] == s[i]) {
					if(s[i] == '(') f[i][j][2] = 2;
					else f[i][j][1] = 2;
				}
			}
		}
	}
	for(int len = 3; len <= n; len++) {
		for(int l = 1; l <= n; l++) {
			int r = l + len - 1;
			if(r > n) break;
			f[l][r][0] = std::max({f[l][r][0], f[l + 1][r][0], f[l][r - 1][0]});
			f[l][r][1] = std::max({f[l][r][1], f[l + 1][r][1], f[l][r - 1][1]});
			f[l][r][2] = std::max({f[l][r][2], f[l + 1][r][2], f[l][r - 1][2]});
			if(s[l] == s[r]) {
				if(s[l] == '(') {
					f[l][r][0] = std::max(f[l + 1][r - 1][1] + 2, f[l][r][0]);
					f[l][r][2] = std::max(f[l + 1][r - 1][0] + 2, f[l][r][2]);
				}
				else {
					f[l][r][0] = std::max(f[l + 1][r - 1][2] + 2, f[l][r][0]);
					f[l][r][1] = std::max(f[l + 1][r - 1][0] + 2, f[l][r][1]);
				}
			}
		}
	}
	int L = n + 1, R = 0;
	for(int i = 1; i <= n; i++) {
		if(s[i] == '(') L = std::min(L, i);
		else R = i;
	}
	int ans = 0;
	if(L < R) ans = std::max(2LL, f[L + 1][R - 1][0] + 2);
	std::cout << ans << '\n';
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
1
25
()()()()()()()()()()))()(
*/
