#include<bits/stdc++.h>
#define int long long
const int N = 100, mod = 998244353, INF = 1e18;
int n, a[N][N], ans[N][N], vis[N][N];
int U[N], L[N], D[N], R[N], ans_num, visL[N][N];
void dfs(int x, int y) {
	if(x == n + 1 && y == 1) {
		for(int i = 1; i <= n; i++) {
			if(!U[i]) continue;
			int maxn = -INF, cnt = 0;
			for(int j = 1; j <= n; j++) {
				if(maxn < a[j][i]) {
					maxn = a[j][i];
					cnt++;
				}
			}
			if(cnt != U[i]) return;
		}
		for(int i = 1; i <= n; i++) {
			if(!D[i]) continue;
			int maxn = -INF, cnt = 0;
			for(int j = n; j >= 1; j--) {
				if(maxn < a[j][i]) {
					maxn = a[j][i];
					cnt++;
				}
			}
			if(cnt != D[i]) return;
		}
		for(int i = 1; i <= n; i++) {
			if(!L[i]) continue;
			int maxn = -INF, cnt = 0;
			for(int j = 1; j <= n; j++) {
				if(maxn < a[i][j]) {
					maxn = a[i][j];
					cnt++;
				}
			}
			if(cnt != L[i]) return;
		}
		for(int i = 1; i <= n; i++) {
			if(!R[i]) continue;
			int maxn = -INF, cnt = 0;
			for(int j = n; j >= 1; j--) {
				if(maxn < a[i][j]) {
					maxn = a[i][j];
					cnt++;
				}
			}
			if(cnt != R[i]) return;
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				ans[i][j] = a[i][j];
//				std::cout << ans[i][j] << ' ';
			}
//			std::cout << '\n';
		}
//		std::cout << '\n';
		ans_num++;
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(vis[x][i]) continue;
		if(visL[y][i]) continue;
		vis[x][i]=  true;
		visL[y][i] = true;
		a[x][y] = i;
		if(y == n) dfs(x + 1, 1);
		else dfs(x, y + 1);
		vis[x][i] = false;
		visL[y][i] = false;
	}
}
void solve() {
	std::cin >> n;
	for(int i = 0; i < n + 2; i++) {
		std::string s;
		std::cin >> s;
		for(int j = 0; j < n + 2; j++) {
			int x = s[j] - '0';
			if(!i) U[j] = x;
			if(i == n + 1) D[j] = x;
			if(!j) L[i] = x;
			if(j == n + 1) R[i] = x;
		}
	}
	dfs(1, 1);
	std::cout << ans_num << '\n';
	if(!ans_num || ans_num > 1) {
		std::cout << "Bad problem -_-";
		return;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			std::cout << ans[i][j];
			if(j != n) std::cout << ' ';
		}
		std::cout << '\n';
	}
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T = 1;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
