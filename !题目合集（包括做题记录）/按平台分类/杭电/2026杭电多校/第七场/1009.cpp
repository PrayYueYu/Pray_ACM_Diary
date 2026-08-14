#include<bits/stdc++.h>
#define int long long
const int N = 1e3 + 10, mod = 998244353, INF = 1e18;
int f[N][N][3], n, m, s, k[N], c[N];
void solve() {
	std::cin >> n >> m >> s;
	for(int i = 1; i <= m; i++) {
		std::cin >> k[i] >> c[i];
	}
	int cur = 1, pre = 0;
	for(int i = 0; i <= m + 1; i++) {
		for(int j = 0; j <= n + 1; j++) {
			f[i][j][cur] = INF;
		}
	}
	f[0][s][cur] = 0;
	for(int s = 1; s <= m; s++) {
		cur ^= 1; pre ^= 1;
		for(int i = 0; i <= m + 1; i++) {
			for(int j = 0; j <= n + 1; j++) {
				f[i][j][cur] = INF;
			}
		}
		for(int i = 0; i <= s; i++) {
			std::deque<int> dq;
			for(int j = 1; j <= n; j++) {
				if(!dq.empty() && dq.front() < j - k[s] + 1) dq.pop_front();
				while(!dq.empty() && f[i][dq.back()][pre] >= f[i][j][pre]) dq.pop_back();
				dq.push_back(j);
				f[i][j][cur] = std::min(f[i][j][cur], f[i][dq.front()][pre]);
				if(j - k[s] >= 1) f[i][j][cur] = std::min(f[i][j][cur], f[i][j - k[s]][pre] + c[s]);
				else if(i) f[i][1][cur] = std::min(f[i][1][cur], f[i - 1][j][pre] + c[s]);
			}
			
			dq.clear();
			for(int j = n; j >= 1; j--) {
				if(!dq.empty() && dq.front() > j + k[s] - 1) dq.pop_front();
				while(!dq.empty() && f[i][dq.back()][pre] >= f[i][j][pre]) dq.pop_back();
				dq.push_back(j);
				f[i][j][cur] = std::min(f[i][j][cur], f[i][dq.front()][pre]);
				if(j + k[s] <= n) f[i][j][cur] = std::min(f[i][j][cur], f[i][j + k[s]][pre] + c[s]);
				else if(i) f[i][n][cur] = std::min(f[i][n][cur], f[i - 1][j][pre] + c[s]);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		int maxn, ans = -1; std::cin >> maxn;
		for(int j = m; j >= 0; j--) {
			if(f[j][i][cur] <= maxn) {
				ans = j;
				break;
			}
		}
		std::cout << ans << ' ';
	}
	std::cout << '\n';
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
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
	Writer: ÔÂö§Þ±‹¬ | 
----------------------
*/
