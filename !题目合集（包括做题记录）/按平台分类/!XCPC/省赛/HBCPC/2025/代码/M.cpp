#include<bits/stdc++.h>
#define int long long
const int N = 2e3 + 10, mod = 998244353, INF = 1e18;
int n, m, vis[N], rk[10], p[10], ac[N], num[N];
std::vector<int> v[N];
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
void dfs(int t, int cnt) {
	if(t == n + 1) {
		if(cnt < 10 || cnt > 13) return;
		for(int i = 1; i <= m; i++) {
			ac[i] = -num[i];
		}
		std::sort(ac + 1, ac + m + 1);
		for(int i = 1; i <= m; i++) {
			ac[i] = -ac[i];
			if(i == rk[1]) {
				if(ac[i] != p[1]) return;
			}
			if(i == rk[2]) {
				if(ac[i] != p[2]) return;
			}
			if(i == rk[3]) {
				if(ac[i] != p[3]) return;
			}
		}
		std::cout << cnt << '\n';
		for(int i = 1; i <= n; i++) {
			if(!vis[i]) continue;
			std::cout << i << ' ';
		}
		exit(0);
	}
	vis[t] = true;
	for(auto x: v[t]) num[x]++;
	dfs(t + 1, cnt + 1);
	for(auto x: v[t]) num[x]--;
	vis[t] = false;
	dfs(t + 1, cnt);
}
void solve() {
	n = read(), m = read();
	for(int i = 1; i <= m; i++) {
		std::string s;
		std::cin >> s;
		s = " " + s;
		for(int j = 1; j <= n; j++) {
			if(s[j] == '1') v[j].push_back(i);
		}
	}
	for(int i = 1; i <= 3; i++) rk[i] = read();
	for(int i = 1; i <= 3; i++) p[i] = read();
	dfs(1, 0);
	std::cout << -1;
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
