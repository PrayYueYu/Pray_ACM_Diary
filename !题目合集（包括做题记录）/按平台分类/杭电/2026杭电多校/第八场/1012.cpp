#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, m, k;
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
std::map<int, int> mp;
int calc(int u, int v) {
	int ans = mp[u + v * (n + 1)];
	mp[u + v * (n + 1)]++;
	return ans;
}
void solve() {
	std::cin >> n >> m >> k;
	int ans = 0;
	for(int i = 1; i <= m; i++) {
		int u, v;
		std::cin >> u >> v;
		if(u > v) std::swap(u, v);
		ans += calc(u, v);
		ans %= mod;
	}
	if(k >= 3) {
		std::cout << "0\n";
		return;
	}
	std::cout << ans << '\n';
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
		mp.clear();
//		init();
	}
	return 0;
}
/*
----------------------
	Writer: ÔÂö§Þ±‹¬ | 
----------------------
*/
