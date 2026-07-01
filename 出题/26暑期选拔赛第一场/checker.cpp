#include<bits/stdc++.h>
#define int long long
const int N = 1e3 + 10, mod = 998244353, INF = 1e18;
int sum;
signed main() {
	for(int tt = 1; tt <= 20; tt++) {
		std::string ss = std::to_string(tt) + ".in";
		freopen(ss.c_str(), "r", stdin);
		int T;
		std::cin >> T;
		sum = 0;
		while(T--) {
			int n, m;
			std::cin >> n >> m;
			for(int i = 1; i <= n; i++) {
				std::string s = "";
				std::cin >> s;
			}
			for(int i = 1; i <= n; i++) {
				std::string s;
				std::cin >> s;
			}
			sum += n * m;
		}
		if(sum > 1000000) std::cout << "NO\n";
		else std::cout << "YES\n";
	}
	return 0;
}
/*
	Writer: ÔÂö§Þ±‹¬ 
*/
