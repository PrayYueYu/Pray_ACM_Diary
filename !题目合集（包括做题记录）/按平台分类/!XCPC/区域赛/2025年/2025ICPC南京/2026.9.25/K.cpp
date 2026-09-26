#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int xn, yn, xr, yr;
int dx[10] = {0, 2, 2, -2, -2, 1, -1, 1, -1};
int dy[10] = {0, 1, -1, 1, -1, 2, 2, -2, -2};
int dxx[10] = {0, 1, 1, -1, -1, 0, 0, 0, 0};
int dyy[10] = {0, 0, 0, 0, 0, 1, 1, -1, -1};
bool check(int sx, int sy) {
	if(sx == xr || sy == yr) return true;
	return false;
}
void solve() {
	std::cin >> xn >> yn >> xr >> yr;
	int f = true;
	for(int i = 1; i <= 8; i++) {
		int sx = xn + dx[i];
		int sy = yn + dy[i];
		int tx = xn + dxx[i];
		int ty = yn + dyy[i];
		if(sx < 1 || sx > 9 || sy < 1 || sy > 10) continue;
		if(tx == xr && ty == yr) continue;
//		std::cout << sx << ' ' << sy << '\n';
		if(!check(sx, sy)) f = false;
	} 
	if(f) std::cout << "YES\n";
	else std::cout << "NO\n";
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
	Writer: ÔÂö§Þ±‹¬ | 
----------------------
*/
