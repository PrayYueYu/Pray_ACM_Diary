#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
void solve() {
	int n; std::cin >> n;
	std::string ans[10];
	ans[0] = "No";
	ans[1] = "Yes";
	int x = (n & 1);
	std::cout << ans[x];
	
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
