#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
const int N = 1e5 + 10, mod = 100000007, INF = 1e18;
int f[N][3][3], n;
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
void init() {
	for(int i = 0; i <= n + 2; i++) {
		for(int j = 0; j <= 2; j++) {
			for(int k = 0; k <= 2; k++) {
				f[i][j][k] = 0;
			}
		}
	}
}
void solve() {
	std::string s;
	std::cin >> s;
	n = s.size();
	s = " " + s;
	if(n == 1) {
		if(s[1] == '0') {
			std::cout << 1 << '\n';
			return;
		}
		if(s[1] == '1') {
			std::cout << 2 << '\n';
			return;
		}
		if(s[1] == '2') {
			std::cout << 1 << '\n';
			return;
		}
		std::cout << 0 << '\n';
		return;
	}
	if(s[1] > '4' || s[n] > '4') {
		std::cout << 0 << '\n';
		return;
	}
	if(s[1] == '0') {
		f[2][0][0] = 1;
	}
	if(s[1] == '1') {
		f[2][0][1] = 2;
		f[2][1][0] = 2;
	}
	if(s[1] == '2') {
		f[2][1][1] = 4;
		f[2][2][0] = 1;
		f[2][0][2] = 1;
	}
	if(s[1] == '3') {
		f[2][1][2] = 2;
		f[2][2][1] = 2;
	}
	if(s[1] == '4') {
		f[2][2][2] = 1;
	}
	for(int i = 3; i <= n; i++) {
		if(s[i - 1] > '6') {
			std::cout << 0 << '\n';
			return;
		}
		for(int j = 0; j <= 2; j++) {
			for(int k = 0; k <= 2; k++) {
				int x = s[i - 1] - '0' - j - k;
				if(x < 0 || x > 2) continue;
				if(j == 1) f[i][j][k] = (f[i - 1][k][x] * 2ll) % mod;
				else f[i][j][k] = f[i - 1][k][x];
			}
		}
	}
	int ans = 0;
	if(s[n] == '0') ans = f[n][0][0];
	if(s[n] == '1') ans = (f[n][1][0] + f[n][0][1]) % mod;
	if(s[n] == '2') ans = (f[n][2][0] + f[n][0][2] + f[n][1][1]) % mod;
	if(s[n] == '3') ans = (f[n][2][1] + f[n][1][2]) % mod;
	if(s[n] == '4') ans = f[n][2][2];
	std::cout << ans << '\n';
}
signed main() {
//	freopen("1.out", "w", stdout);
	int T = read();
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*
------------------------------
	Writer: yueyuweihu
	Blog: prayyueyu.github.io
------------------------------
test:

*/
