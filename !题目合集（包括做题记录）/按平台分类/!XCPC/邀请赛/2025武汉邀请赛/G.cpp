#include<bits/stdc++.h>
#define int long long
const int N = 2e5 + 10, mod = 998244353, INF = 1e18;
int n, m, g[N];
int fac[N], invfac[N];
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
std::vector<std::pair<int, int>> v[N];
std::vector<std::vector<int>> a, f;
void init() {
	for(int i = 0; i <= n * m; i++) {
		v[i].clear();
	}
	a.clear(), f.clear();
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
void pre() {
	fac[0] = 1;
	for(int i = 1; i <= 1e5; i++) {
		fac[i] = fac[i - 1] * i % mod;
	}
	invfac[100000] = ksm(fac[100000], mod - 2);
	for(int i = 100000 - 1; i >= 0; i--) {
		invfac[i] = invfac[i + 1] * (i + 1) % mod;
	}
}
int C(int x, int y) {
	if(x < y) return 0;
	int ans = fac[x];
	ans = ans * invfac[y] % mod;
	ans = ans * invfac[x - y] % mod;
	return ans;
}
int solve1(int t) {
	v[t].push_back({n, m}); 
	for(int i = 0; i <= v[t].size(); i++) g[i] = 0;
	std::sort(v[t].begin(), v[t].end());
	for(int i = 0; i < v[t].size(); i++) {
		int x = v[t][i].first, y = v[t][i].second;
		g[i] = C(x + y - 2, x - 1);
		for(int j = 0; j < i; j++) {
			if(v[t][j].second > v[t][i].second) continue;
			int dx = x - v[t][j].first, dy = y - v[t][j].second;
			g[i] = (g[i] - g[j] * C(dx + dy, dx) % mod + mod) % mod;
		}
	}
	return g[v[t].size() - 1];
}
int solve2(int t) {
	for(int i = 0; i <= n + 1; i++) {
		for(int j = 0; j <= m + 1; j++) {
			f[i][j] = 0;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(a[i][j] == t) {
				f[i][j] = 0;
				continue;
			}
			if(i == 1 && j == 1) {
				f[i][j] = 1;
				continue;
			}
			f[i][j] = (f[i - 1][j] + f[i][j - 1]) % mod;
		}
	}
	return f[n][m];
}
void solve() {
	n = read(), m = read();
	a.resize(n + 3, std::vector<int>(m + 3));
	f.resize(n + 3, std::vector<int>(m + 3));
	int st = 0, ed = 0, ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			a[i][j] = read();
			v[a[i][j]].push_back({i, j});
			if(i == 1 && j == 1) st = a[i][j];
			if(i == n && j == m) ed = a[i][j];//特判 
		}
	}
	for(int i = 1; i <= n * m; i++) {
		if(!v[i].size()) continue;
		ans += C(n + m - 2, n - 1); ans %= mod;
		if(st == i || ed == i) continue;//起点/终点特判 
		if(v[i].size() <= sqrt(n * m)) {
			ans = (ans - solve1(i) + mod) % mod;
		}
		else ans = (ans - solve2(i) + mod) % mod;
		//solve12是不经过i这个值的所有方案数 
	}
	std::cout << ans << '\n';
}
signed main() {
	pre();
	int T = read();
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*

*/
