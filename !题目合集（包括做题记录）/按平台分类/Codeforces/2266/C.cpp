#include<bits/stdc++.h>
#define int long long
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int n, f[N][2];
std::string s;
int r(int x) {
	return 1 - x;
}
void solve() {
	std::cin >> n >> s;
	f[0][s[0] - '0'] = 0;
	f[0][r(s[0] - '0')] = INF;
	int cnt1 = 0, cnt0 = 0;
	if(s[0] == '0') cnt0++;
	else cnt1++;
	for(int i = 1; i < n; i++) {
		if(s[i] == '0') {
			f[i][0] = f[i - 1][0];
			if(cnt1) f[i][1] = std::min(f[i - 1][0], f[i - 1][1]) + 1;
			else f[i][1] = INF;
			cnt0++;
		}
		else {
			if(cnt0) f[i][0] = f[i - 1][0] + 1;
			else f[i][0] = INF;
			f[i][1] = std::min(f[i - 1][0], f[i - 1][1]); 
			cnt1++;
		}
	}
	std::cout << std::min(f[n - 1][1], f[n - 1][0]) << '\n';
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
