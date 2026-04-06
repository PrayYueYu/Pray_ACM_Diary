#include<bits/stdc++.h>
#define int long long
const int N = 2e5 + 10, mod = 998244353, INF = 1e18;
std::vector<int> ans, s[N][3];
int n, m, st, l[N], r[N], vis[N];
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
void dfs(int x, int to) {
	if(vis[x]) return;
	ans.push_back(x);
	vis[x] = true;
	for(auto ne: s[x][to]) {
		dfs(ne, to);
	}
}
void solve() {
	n = read(), m = read(), st = read();
	for(int i = 1; i <= m; i++) {
		l[i] = read(), r[i] = read();
		s[l[i]][1].push_back(r[i]);
		s[r[i]][0].push_back(l[i]);
	}
	for(int i = 1; i <= m; i++) {
		if(l[i] <= st && st <= r[i]) {
			dfs(l[i], 0);
			dfs(r[i], 1);
			
		}
	}
	std::sort(ans.begin(), ans.end());
	for(auto x: ans) {
		if(x == st) continue;
		std::cout << x << ' ';
	}
}
signed main() {
	int T = 1;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
