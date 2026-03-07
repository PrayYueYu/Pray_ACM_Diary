#include<bits/stdc++.h>
#define int long long
const int N = 1e5 + 10, mod = 998244353, INF = 1e18;
int n, f[N], m, k, v[N];
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
	n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		f[i] = read();
	}
	k = read();
	for(int i = 1; i <= k; i++) {
		while(true) {
			int x = read();
			if(!x) break;
			v[f[x]]++;
		}
		std::vector<std::pair<int, int>> ans;
		for(int j = 1; j <= m; j++) {
			if(!v[j]) continue;
			ans.push_back({j, v[j]});
			v[j] = 0;
		}
		for(int j = 0; j < ans.size(); j++) {
			std::cout << "B" << ans[j].first;
			std::cout << '-' << ans[j].second;
			if(j != ans.size() - 1) std::cout << ' ';
		}
		if(i != k) std::cout << '\n';
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
