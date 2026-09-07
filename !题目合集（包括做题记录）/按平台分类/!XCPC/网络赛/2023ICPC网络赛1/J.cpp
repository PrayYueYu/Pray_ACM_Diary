#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
double r1, r2, xr1, xr2, yr1, yr2;
int x1, x2, y1, y2;
double calc(int x1, int y1, int x2, int y2) {
	double ans = sqrt((double)(x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	return ans;
}
void solve() {
	std::cin >> x1 >> y1 >> x2 >> y2;
	xr1 = (x1 + x2) / 2.0;
	yr1 = (y1 + y2) / 2.0;
	r1 = calc(x1, y1, x2, y2) / 2.0;
	
	std::cin >> x1 >> y1 >> x2 >> y2;
	xr2 = (x1 + x2) / 2.0;
	yr2 = (y1 + y2) / 2.0;
	r2 = calc(x1, y1, x2, y2) / 2.0;	
	
	double ans = std::fabs(xr1 - xr2) + std::fabs(yr1 - yr2);
	ans -= sqrt(2) * r2;
	
	printf("%.10lf\n", ans);
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
	Writer: ÔÂö§Ş±‹¬ | 
----------------------
*/
