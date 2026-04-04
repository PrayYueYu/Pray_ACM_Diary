#include<bits/stdc++.h>
#define int long long
#define double long double
const int N = 2e4 + 10, mod = 998244353, INF = 1e18;
int n, fac[N], invfac[N], a[N], fa[N], to[N];
double lgfac[N];
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

inline double getC(int x, int y) {
	int maxn = std::max(a[x], a[y]);
	int minn = std::min(a[x], a[y]);
	double ans = lgfac[maxn] - lgfac[minn] - lgfac[maxn - minn];
	return ans;
}
inline int C(int x, int y) {
	if(y > x) return 0;
	int ans = fac[x] * invfac[y] % mod;
	ans = ans * invfac[x - y] % mod;
	return ans;
}
inline int ksm(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = ans * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return ans;
}
int getfa(int x) {
	if(x == fa[x]) return x;
	return fa[x] = getfa(fa[x]);
}
std::priority_queue<std::pair<double, std::pair<int, int>>> q;
void solve() {
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
		fa[i] = i;
		to[i] = i + 1;
	}
	while(!q.empty()) q.pop();
	std::sort(a + 1, a + n + 1);
	for(int i = 1; i < n; i++) {
		q.push({-getC(i, i + 1), {i, i + 1}});
		
	}
	int cnt = 0, ans = 0;
	while(!q.empty()) {
		int u = q.top().second.first;
		int v = q.top().second.second;
		q.pop();
		int fau = getfa(u), fav = getfa(v);
		if(fau == fav) continue;
		cnt++;
		fa[fau] = fav;
		ans += C(a[v], a[u]));
		ans %= mod;
		to[u]
		if(to[u] < n) {
			to[u]++;
//			std::cout << u << ' ' << to[u] << '\n';
			q.push({-getC(u, to[u]), {u, to[u]}});
		}
		if(cnt >= n - 1) break;
	}
	std::cout << ans << '\n';
}
signed main() {
	fac[0] = 1;
	for(int i = 1; i <= 5000; i++) {
		lgfac[i] = lgfac[i - 1] + log1p(i);
		fac[i] = fac[i - 1] * i % mod;
	}
	invfac[5000] = ksm(fac[5000], mod - 2);
	for(int i = 4999; i >= 0; i--) {
		invfac[i] = invfac[i + 1] * (i + 1) % mod;
	}       
	int T = read();
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
