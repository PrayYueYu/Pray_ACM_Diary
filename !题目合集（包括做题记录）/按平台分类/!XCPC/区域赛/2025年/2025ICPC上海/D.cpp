#include<bits/stdc++.h>
const int N = 2e6 + 10, mod = 998244353;
int f[50000000], n, a[N], ans, p3[100];
void dfs(int t, int x, int now) {
	//位数，第 x 位为 2，当前数为 now
	if(t == n) {
		if(x == -1) ans = ans ^ f[now];
		else {
			int s1 = now - p3[x];
			int s2 = now - p3[x] * 2;
			f[now] = f[s1] + f[s2];
			ans = ans ^ f[now];
		}
		return;
	}
	dfs(t + 1, x, now);
	dfs(t + 1, x, now + p3[t]);
	dfs(t + 1, t, now + p3[t] * 2);
}
void solve() {
	p3[0] = 1;
	for(int i = 1; i <= 17; i++) p3[i] = p3[i - 1] * 3;
	std::cin >> n;
	for(int i = 0; i < (1 << n); i++) {
		std::cin >> a[i];
		int now = 0;
		for(int j = 0; j < n; j++) {
			if(i >> j & 1) now = now + p3[j];
		}
		f[now] = a[i];
	}
	dfs(0, -1, 0);
	std::cout << ans << '\n';
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}
/*
----------------------
	Writer: 月雩薇嫭 | 
----------------------
*/
