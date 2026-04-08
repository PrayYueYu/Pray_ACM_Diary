#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, ans = -1, cnt[100], mx[10];
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
std::vector<int> p[100];
void dfs(int t, int res, int val) {
	if(t == 10) {
		ans = std::max(ans, val);
		return;
	}
	if(t == 5 || t == 7 || t == 8) {
		dfs(t + 1, res, val);
		return;
	}
	dfs(t + 1, res, val);
	for(int i = p[t].size() - 1; i >= std::max(0ll, (int)p[t].size() - mx[t]); i--) {
		if(res - t < 0) break;
		res -= t;
		val += p[t][i];
		cnt[t]++;
		dfs(t + 1, res, val);
	}
}
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) {
		int a = read(), b = read(), v = read();
		p[a * b].push_back(v);
	}
	std::sort(p[1].begin(), p[1].end());
	std::sort(p[2].begin(), p[2].end());
	std::sort(p[3].begin(), p[3].end());
	std::sort(p[4].begin(), p[4].end());
	std::sort(p[6].begin(), p[6].end());
	std::sort(p[9].begin(), p[9].end());
	ans = -1;
	dfs(1, 9, 0);
	std::cout << ans << '\n';
	for(int i = 0; i <= 9; i++) {
		p[i].clear();
		cnt[i] = 0;
	}
}
signed main() {
	mx[1] = 9, mx[2] = 4, mx[3] = 3;
	mx[4] = 1, mx[6] = 1, mx[9] = 1;
	int T = read();
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
2
2
1 1 13141314
3 3 69473110
5
2 3 20
1 3 5
1 2 4
1 1 4
1 3 6
*/
