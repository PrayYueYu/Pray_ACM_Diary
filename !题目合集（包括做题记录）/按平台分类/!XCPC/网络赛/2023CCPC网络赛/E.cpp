#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, g[1000][1000], maxn = 100, vis[100], tx;
std::string s;
std::vector<std::pair<int, int>> ans;
void dfs(int t) {
	if(t == n + 1) {
		int nowx = 0, nowy = 0;
		tx++;
		g[maxn][maxn] = 2 * tx;
		for(int i = 1; i <= n; i++) {
			int nex = nowx, ney = nowy;
			if(s[i] == 'R') nex++;
			if(s[i] == 'L') nex--;
			if(s[i] == 'D') ney--;
			if(s[i] == 'U') ney++;
			if(vis[i]) {
				if(g[maxn + nex][maxn + ney] == 2 * tx + 1) return;
				nowx = nex, nowy = ney;
				g[maxn + nowx][maxn + nowy] = 2 * tx;
			}
			else {
				if(g[maxn + nex][maxn + ney] == 2 * tx) return;
				g[maxn + nex][maxn + ney] = 2 * tx + 1;
			}
		}
		
		ans.push_back({nowx, nowy});
		return;
	}
	vis[t] = true;
	dfs(t + 1);
	vis[t] = false;
	dfs(t + 1);
}
void solve() {
	std::cin >> n;
	std::cin >> s;
	s = " " + s;
	dfs(1);
	std::sort(ans.begin(), ans.end());
	int num = 1;
	for(int i = 1; i < ans.size(); i++) {
		if(ans[i].first == ans[i - 1].first && ans[i].second == ans[i - 1].second) {
			continue;
		}
		num++;
	}
	std::cout << num << '\n';
	std::cout << ans[0].first << ' ' << ans[0].second << '\n';
	for(int i = 1; i < ans.size(); i++) {
		if(ans[i].first == ans[i - 1].first && ans[i].second == ans[i - 1].second) {
			continue;
		}
		std::cout << ans[i].first << ' ' << ans[i].second << '\n';
	}
}
signed main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(0);
//	std::cout.tie(0);
	int T = 1; 
//	std::cin >> T; 
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
----------------------
	Writer: ÔÂö§Þ±‹¬ | 
----------------------
*/
