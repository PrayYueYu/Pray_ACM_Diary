#include<bits/stdc++.h>
#define int long long
const int N = 2e4 + 10, mod = 998244353, INF = 1e18;
int n, dp[N];
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

void solve() {
	n = read();
	std::vector<int> ans, ask;
	for(int i = 1; i <= n * n + 1; i++) {
		ask.push_back(i);
		dp[i] = n + 1;
	}
	for(int i = 1; i <= n; i++) {
		std::cout << "? " << ask.size() << ' ';
		for(auto x: ask) std::cout << x << ' ';
		std::cout << '\n';
		std::cout.flush();
		int cnt = read();
		std::vector<int> rx, d;
		for(int j = 1; j <= cnt; j++) {
			int x = read();
			d.push_back(x);
		}
		if(cnt >= n + 1) {
			std::cout << "! ";
			for(int j = 0; j < n + 1; j++) {
				std::cout << d[j] << ' ';
			}
			std::cout << '\n';
			std::cout.flush();
			return;
		}
		for(auto x: ask) {
			if(!binary_search(d.begin(), d.end(), x)) {
				rx.push_back(x);
			}
			else dp[x] = i;
		}
		ask = rx;
	}
	int res = n + 1;
	for(int i = n * n + 1; i >= 1; i--) {
		if(dp[i] == res) {
			ans.push_back(i);
			res--;
		}
	}
	std::reverse(ans.begin(), ans.end());
	std::cout << "! ";
	for(auto x: ans) std::cout << x << ' ';
	std::cout << '\n';
	std::cout.flush();
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(0);
	int T = read();
	while(T--) {
		solve();
	}
	return 0;
}
/*

*/
