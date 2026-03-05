#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, d[1000][1000], gen[1000];
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
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			d[i][j] = INF;
		}
	}
	for(int i = 1; i <= n; i++) {
		char c; std::cin >> c;
		if(c == 'F') gen[i] = 0;
		else gen[i] = 1;
//		std::cout << gen[i] << '\n';
		int cnt = 0;
		cnt = read();
		for(int j = 1; j <= cnt; j++) {
			int x = read(), y = read();
			d[i][x] = y;
		}
	}
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	std::vector<int> ans[3];
	int minn[10] = {INF, INF, INF, INF};
	for(int i = 1; i <= n; i++) {
		int now_maxn = -INF;
		for(int j = 1; j <= n; j++) {
//			std::cout << i << "->" << j << ": " << d[i][j] << '\n';
			if(gen[i] == gen[j]) continue;
			now_maxn = std::max(now_maxn, d[j][i]);
		}
		if(now_maxn < minn[gen[i]]) {
			minn[gen[i]] = now_maxn;
			ans[gen[i]].clear();
			ans[gen[i]].push_back(i);
		}
		else if(now_maxn == minn[gen[i]]) {
			ans[gen[i]].push_back(i);
		}
	}
	for(int i = 0; i < ans[0].size(); i++) {
		std::cout << ans[0][i];
		if(i != ans[0].size() - 1) std::cout << ' ';
	}
	std::cout << '\n';
	for(int i = 0; i < ans[1].size(); i++) {
		std::cout << ans[1][i];
		if(i != ans[1].size() - 1) std::cout << ' ';
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
