#include<bits/stdc++.h>
#define int long long
const int N = 1e3 + 10, mod = 998244353, INF = 1e18;
int sum[N][N], maxn[N][N], a[N][N], fc[N][N], sumf[N][N];
int n, m, c, f, to[N][N];
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
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= m; j++) {
			sum[i][j] = sumf[i][j] = 0;
			to[i][j] = maxn[i][j] = fc[i][j] = 0;
		}
	}
}
void solve1() {
	int ans1 = 0, ans2 = 0;
	for(int i = 1; i <= n; i++) {
		int cnt = 0;
		for(int j = m; j >= 1; j--) {
			if(a[i][j]) cnt = 0;
			else cnt++;
			if(cnt) maxn[i][j] = cnt - 1;
			else maxn[i][j] = cnt;
			if(a[i][j]) sum[i][j] = 0;
			sum[i][j] = sum[i - 1][j] + maxn[i][j];
		}
	}
	for(int j = 1; j <= m; j++) {
		int l = 0;
		for(int i = 1; i <= n; i++) {
			if(a[i][j]) l = 0;
			else if(!l) l = i;
			to[i][j] = l;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			sumf[i][j] = sumf[i - 1][j];
			if(a[i][j]) continue;
			if(to[i][j] > i - 2) continue;
			int now = sum[i - 2][j] - sum[to[i][j] - 1][j];
			fc[i][j] = now * maxn[i][j] % mod;
			sumf[i][j] = (sumf[i][j] + fc[i][j]) % mod;
			ans1 = (ans1 + fc[i][j]) % mod;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(a[i][j]) continue;
			if(i - to[i][j] + 1 < 4) continue;
			ans2 = (ans2 + (sumf[i - 1][j] - sumf[to[i][j] - 1][j])) % mod;
		}
	}
	std::cout << (ans1 * c) % mod << ' ' << (ans2 * f) % mod << '\n';
}
void solve() {
	n = read(), m = read(), c = read(),  f = read();
	for(int i = 1; i <= n; i++) {
		std::string s;
		std::cin >> s;
		s = " " + s;
		for(int j = 1; j <= m; j++) {
			a[i][j] = s[j] - '0';
//			a[i][j] ^= 1;
		}
	}
	solve1();
}
signed main() {
//	freopen("plant11.in", "r", stdin);
	int T, id; std::cin >> T >> id;
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*

*/
