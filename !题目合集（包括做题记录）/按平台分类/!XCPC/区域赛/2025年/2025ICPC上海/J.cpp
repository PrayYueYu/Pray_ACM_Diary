#include<bits/stdc++.h>
const int N = 5e5 + 10, mod = 998244353;
int n, m, k, cnt, ans[N];
std::vector<int> r[N][10];
void dfs(std::vector<int> &f, int p) {
	if(cnt > k) return;
	for(int i = 1; i <= 8; i++) {
		std::vector<int> g;
		for(auto x: f) {
			for(auto y: r[x][i]) {
				if(cnt > k) return;
				ans[++cnt] = p;
				g.push_back(y);
			}
		}
		if(cnt > k) return;
		if(!g.size()) continue;
		dfs(g, p + 1);
	}
}
void solve() {
	std::cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		int u, v, e;
		std::cin >> u >> v >> e;
		r[u][e].push_back(v);
	}
	for(int i = 1; i <= k; i++) ans[i] = -1;
	std::vector<int> f;
	for(int i = 1; i <= n; i++) f.push_back(i); 
	dfs(f, 1);
	for(int i = 1; i <= k; i++) std::cout << ans[i] << '\n';
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	solve();
	return 0;
}
/*
----------------------
	Writer: ÔÂö§Þ±‹¬ | 
----------------------
*/
