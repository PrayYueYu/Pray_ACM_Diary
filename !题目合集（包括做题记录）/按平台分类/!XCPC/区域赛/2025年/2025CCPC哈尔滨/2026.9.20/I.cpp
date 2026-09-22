#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;

void solve() {
	int n, m, sx = 0, sy = 0, sz = 0;
	std::cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		int x, y, z;
		std::cin >> x >> y >> z;
		sx += x;
		sy += y;
		sz += z;
	}
	for(int i = 1; i <= m; i++) {
		int x, y, z;
		std::cin >> x >> y >> z;
		sx -= x;
		sy -= y;
		sz -= z;
	}
	if(sx % 6 == 0 && sy % 6 == 0 && sz % 6 == 0) {
		std::cout << "YES\n";
	}
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
1
9 7
0 2 -2
-2 2 0
0 1 -1
2 0 -2
-1 0 1
2 -2 0
0 -2 2
0 0 0
-2 1 1
-1 1 0
1 1 -2
2 0 -2
2 -1-1
0 -1 1
0 -2 2
1 -2 1

2
4 2 
-1 1 0 
-1 0 1
0 -1 1
1 0 -1
0 1 -1
1 -1 0
4 3 
-1 1 0 
-1 0 1
0 -1 1
1 0 -1
0 0 0
0 1 -1
1 -1 0
*/
