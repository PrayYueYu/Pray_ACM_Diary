#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int a[10][10], b[10][10], c[10][10], n, f[N];
std::string s;
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
	for(int j = 0; j <= 5; j++) {
		for(int k = 0; k <= 2; k++) {
			a[j][k] = b[j][k] = 0;
		}
	}
}
void solve() {
	n = read();
	std::cin >> s;
	s = " " + s;
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int now = s[i] - '0';
		for(int j = 0; j <= 5; j++) {
			for(int k = 0; k <= 2; k++) {
				a[j][k] += b[j][k];
				c[j][k] = 0;
			}
		}
		for(int j = 0; j <= 5; j++) {
			for(int k = 0; k <= 2; k++) {
				c[(j + 1) % 6][(k + now) % 3] = b[j][k];
			}
		}
		c[1][now]++;
		for(int j = 0; j <= 5; j++) {
			for(int k = 0; k <= 2; k++) {
				b[j][k] = c[j][k];
			}
		}
	}
	ans += a[0][0] + a[3][0] + a[2][1] + a[5][1] + a[1][2] + a[4][2];
	ans += b[0][0] + b[3][0] + b[2][1] + b[5][1] + b[1][2] + b[4][2];
	int maxn = 1;
	for(int i = 2; i <= n; i++) {
		if(s[i] != s[i - 1]) {
			maxn++;
			continue;
		}
		else {
			ans += f[maxn];
			maxn = 1;
		}
	}
	ans += f[maxn];
	std::cout << (n * (n + 1)) / 2 - ans << '\n';
}
signed main() {
	for(int i = 1; i <= 1000000; i++) {
		f[i] = f[i - 1] + (i - 1) / 2;
	}
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*
1
5
01001
*/
