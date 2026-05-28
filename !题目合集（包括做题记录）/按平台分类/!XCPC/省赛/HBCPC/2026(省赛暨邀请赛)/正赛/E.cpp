#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, vis[1200][1200];
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
std::vector<int> ans[N];
void solve() {
	n = read();
	int cnt = 0;
	for(int d = 1; d <= n; d++) {
		for(int st = 1; st <= d; st++) {
			if(st + d > n) break;
			std::vector<int> v;
			int now = st;
			while(true) {
				v.push_back(now);
				now += d;
				if(now > n) break;
			}
			if(v.size()) ans[++cnt] = v;
		}
		
	}
	std::cout << cnt << '\n';
	for(int i = 1; i <= cnt; i++) {
		if(ans[i][0] != 1) std::cout << "1 ";
		for(auto x: ans[i]) std::cout << x << ' ';
		if(ans[i][ans[i].size() - 1] != n) std::cout << n;
		std::cout << '\n';
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
