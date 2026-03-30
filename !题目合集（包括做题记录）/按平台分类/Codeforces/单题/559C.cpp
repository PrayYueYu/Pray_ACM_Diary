#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 1e9 + 7, INF = 1e18;
int f[N], fac[N], invfac[N], n, m, k;
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
void pre() {
	fac[0] = 1;
	for(int i = 1; i <= 2e5; i++) {
		fac[i] = fac[i - 1] * i % mod;
	}
	invfac[200000] = ksm(fac[200000], mod - 2);
	for(int i = 200000 - 1; i >= 0; i--) {
		invfac[i] = invfac[i + 1] * (i + 1) % mod;
	}
}
int C(int x, int y) {
	return (fac[x] * invfac[x - y]) % mod * invfac[y] % mod;
}
void solve() {
	n = read(), m = read(), k = read();
	std::vector<std::pair<int, int>> v;
	for(int i = 1; i <= k; i++) {
		int x = read(), y = read();
		v.push_back({x, y});
		if((x == 1 && y == 1) || (x == n && y == m)) {
			std::cout << 0;
			return;
		}
	}
	v.push_back({n, m});
	std::sort(v.begin(), v.end());//自动先按照x排序，再按照y排序 
	for(int i = 0; i < v.size(); i++) {
		int dx = v[i].first - 1, dy = v[i].second - 1;
		//当前点到(1,1)的方案，无果无障碍 
		f[i] = C(dx + dy, dx);
		for(int j = 0; j < i; j++) {
			if(v[j].second > v[i].second) continue;
			//必须满足j在i的左上角，x经过排序已经自动满足了 
			dx = v[i].first - v[j].first;
			dy = v[i].second - v[j].second;
			f[i] = (f[i] - f[j] * C(dx + dy, dy) % mod + mod) % mod;
			//f[i]减去j到i的所有方案数 
		}
	}
	std::cout << f[v.size() - 1];//最后一个点是(n,m)，所以直接输出 
}
signed main() {
	pre();
	int T = 1;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
1
2 3
5 2 1
1 5 5
*/
