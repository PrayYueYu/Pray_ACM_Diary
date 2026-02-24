#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n;
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
std::vector<std::vector<int>> ans;
void solve() {
	n = read();
	ans.resize(n + 3);
	ans[1] = {1, 0};
	for(int i = 2; i <= n; i++) {
		int x = (1 << (i - 1));
		for(int j = 0; j < x; j++) {
			ans[i].push_back(ans[i - 1][j] + x);
		}
		for(int j = x - 1; j >= 0; j--) {
			ans[i].push_back(ans[i - 1][j]);
		}
	}
	for(auto x: ans[n]) std::cout << x << ' ';
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
