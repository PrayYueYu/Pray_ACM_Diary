#include<bits/stdc++.h>
const int N = 2e3 + 10, mod = 998244353;
int sumx[N][N], sumy[N][N], n, m;
std::string s;
bool dfs(int lx, int rx, int ly, int ry) {
	if(rx <= lx || ry <= ly) return true;
	bool f = true;
	for(int i = lx; i < rx; i++) {
		int sum = sumx[i][ry] - sumx[i][ly - 1];
		if(sum == ry - ly + 1) {
			int f1 = dfs(lx, i, ly, ry);
			int f2 = dfs(i + 1, rx, ly, ry);
			return (f1 & f2);
		}
		if(sum) f = false;
	}
	if(f) return true;
	for(int i = ly; i < ry; i++) {
		int sum = sumy[rx][i] - sumy[lx - 1][i];
		if(sum == rx - lx + 1) {
			int f1 = dfs(lx, rx, ly, i);
			int f2 = dfs(lx, rx, i + 1, ry);
			return (f1 & f2);
		}
		if(sum) f = false;
	}
	return f;
}
void solve() {
	std::cin >> n >> m;
	for(int i = 1; i < n; i++) {
		std::cin >> s;
		s = " " + s;
		for(int j = 1; j <= m; j++) {
			sumx[i][j] = sumx[i][j - 1] + s[j] - '0';
		}
	}
	for(int i = 1; i <= n; i++) {
		std::cin >> s;
		s = " " + s;
		for(int j = 1; j < m; j++) {
			sumy[i][j] = sumy[i - 1][j] + s[j] - '0';
		}
	}
	if(dfs(1, n, 1, m)) std::cout << "YES\n";
	else std::cout << "NO\n";
}
signed main() {
//	freopen("1.in", "r", stdin);
	int T = 1; 
//	std::cin >> T;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
