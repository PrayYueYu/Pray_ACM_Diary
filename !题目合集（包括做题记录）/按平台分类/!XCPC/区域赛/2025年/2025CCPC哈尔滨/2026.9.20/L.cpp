#include<bits/stdc++.h>
#define int long long
const int N = 100 + 10, mod = 998244353, INF = 1e18;
int n, m, f[N][N], k, vis[N], r[N], c[N], visx[N][N];

void solve() {
	std::cin >> n >> m;
	std::cin >> k;
	for(int i = 1; i <= k; i++) {
		std::cin >> r[i] >> c[i];
	}
	for(int p = 0; p < (1 << k); p++) {
		for(int i = 0; i < k; i++) {
			vis[i + 1] = (p >> i & 1);
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				f[i][j] = INF;
				visx[i][j] = true;
			}
		} 
		int ans = INF;
		for(int i = 1; i <= n; i++) f[i][1] = 0;
		for(int i = 1; i <= k; i++) {
			if(vis[i] == 0) {//从上方 
				for(int j = r[i]; j <= n; j++) {
					visx[j][c[i]] = false;
				}
			}
			else {//从下方 
				for(int j = 1; j <= r[i]; j++) {
					visx[j][c[i]] = false;
				}
			}
		}
		for(int j = 2; j <= m; j++) {
			for(int i = 1; i <= n; i++) {
				if(!visx[i][j]) continue;
				f[i][j] = std::min(f[i][j], f[i][j - 1] + 1);
			}
			for(int i = 2; i <= n; i++) {
				if(!visx[i][j]) continue;
				f[i][j] = std::min(f[i][j], f[i - 1][j] + 1);
			}
			for(int i = n - 1; i >= 1; i--) {
				if(!visx[i][j]) continue;
				f[i][j] = std::min(f[i][j], f[i + 1][j] + 1);
			}
			if(j == m) {
				for(int i = 1; i <= n; i++)
					ans = std::min(ans, f[i][j]);
			}
		}
		if(ans >= INF) std::cout << -1 << ' ';
		else std::cout << ans << ' ';
	}
	std::cout << '\n';
}
signed main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(0);
//	std::cout.tie(0);
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
----------------------
	Writer: 月雩薇嫭 | 
----------------------
*/
