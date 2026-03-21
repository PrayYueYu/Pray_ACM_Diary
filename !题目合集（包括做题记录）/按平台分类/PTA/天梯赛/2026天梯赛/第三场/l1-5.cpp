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
int getmin(int x) {
	std::vector<int> v;
	for(int i = 1; i <= 4; i++) {
		v.push_back(x % 10);
		x /= 10;
	}
	std::sort(v.begin(), v.end());
	int ans = 0;
	for(auto x: v) ans = ans * 10 + x;
	return ans;
}
int getmax(int x) {
	std::vector<int> v;
	for(int i = 1; i <= 4; i++) {
		v.push_back(x % 10);
		x /= 10;
	}
	std::sort(v.begin(), v.end());
	int ans = 0;
	for(int i = v.size() - 1; i >= 0; i--) ans = ans * 10 + v[i];
	return ans;
}
void solve() {
	n = read();
	std::vector<std::pair<std::pair<int, int>, int>> ans;
	for(int i = 1; i <= 7; i++) {
		int maxn = getmax(n);
		int minn = getmin(n);
		n = maxn - minn;
		ans.push_back({{maxn, minn}, n});
		if(n == 6174) break;
	}
	if(n == 6174) {
		std::cout << ans.size() << '\n';
		for(int i = 0; i < ans.size(); i++) {
			std::cout << ans[i].first.first << " - ";
			std::cout << ans[i].first.second << " = ";
			std::cout << ans[i].second << '\n';
		}
	}
	else std::cout << -1;
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
