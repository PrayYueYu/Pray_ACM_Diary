#include<bits/stdc++.h>
#define int long long
const int N = 2e5 + 10, mod = 998244353, INF = 1e18;
int inv100, p[10], f[20][20];
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
int ksm(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = (ans * x) % mod;
		x = (x * x) % mod;
		y >>= 1;
	}
	return ans;
}
int calc2(int x) {
	int ans = 1;
	for(int i = 1; i <= 7; i++) {
		if(f[x][i] == 1) {
			ans = ((ans * p[i]) % mod * inv100) % mod;
		}
		else {
			ans = (ans * (100 - p[i]) % mod * inv100) % mod;
		}
	}
	return ans;
}
int calc1(int x) {
	int ans = 1;
	for(int i = 1; i <= 4; i++) {
		int now = x % 10;
		ans = (ans * calc2(now)) % mod;
		x /= 10;
	}
	return ans;
}
void solve() {
	int ans = 0, c = read();
	for(int i = 1; i <= 7; i++) p[i] = read();
	for(int i = 0; i <= c; i++) {
		int j = c - i;
		ans += calc1(i) * calc1(j);
		ans %= mod;
	}
	std::cout << ans << '\n';
}
signed main() {
	int T = read();
	inv100 = ksm(100, mod - 2);
	f[0][1] = f[0][2] = f[0][3] = f[0][5] = f[0][6] = f[0][7] = 1;
	f[1][3] = f[1][6] = 1;
	f[2][1] = f[2][3] = f[2][4] = f[2][5] = f[2][7] = 1;
	f[3][1] = f[3][3] = f[3][4] = f[3][6] = f[3][7] = 1;
	f[4][2] = f[4][4] = f[4][3] = f[4][6] = 1;
	f[5][1] = f[5][2] = f[5][4] = f[5][6] = f[5][7] = 1;
	f[6][1] = f[6][2] = f[6][4] = f[6][5] = f[6][6] = f[6][7] = 1;
	f[7][1] = f[7][3] = f[7][6] = 1;
	f[8][1] = f[8][2] = f[8][3] = f[8][4] = f[8][5] = f[8][6] = f[8][7] = 1;
	f[9][1] = f[9][2] = f[9][3] = f[9][4] = f[9][6] = f[9][7] = 1;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
