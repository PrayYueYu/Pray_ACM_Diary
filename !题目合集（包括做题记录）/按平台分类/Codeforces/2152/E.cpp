#include<bits/stdc++.h>
#define int long long
const int N = 2e4 + 10, mod = 998244353, INF = 1e18;
int n, d[N], vis[N];
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
void init() {
	for(int i = 0; i <= n * n + 1; i++) vis[i] = false;
}
void solve() {
	n = read();
	std::vector<int> ans;
	for(int i = 1; i <= n; i++) {
		std::vector<int> ask;
		for(int j = 1; j <= n * n + 1; j++) {
			if(vis[j]) continue;
			ask.push_back(j);
		} 
		std::cout << "? " << ask.size() << ' ';
		for(auto x: ask) std::cout << x << ' ';
		std::cout << '\n';
		std::cout.flush();
		int cnt = read();
		for(int j = 1; j <= cnt; j++) {
			d[j] = read();
			vis[d[j]] = true;
		}
		if(cnt >= n + 1) {
			std::cout << "! ";
			for(int j = 1; j <= n + 1; j++) {
				std::cout << d[j] << ' ';
			}
			std::cout << '\n';
			std::cout.flush();
			return;
		}
		ans.push_back(d[cnt]);
	}
	std::cout << "! ";
	for(auto x: ans) std::cout << x << ' ';
	std::cout << ans[ans.size() - 1] + 1 << '\n';
	std::cout.flush();
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(0);
	int T = read();
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*

*/
