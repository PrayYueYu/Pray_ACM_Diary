#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, a[N], vis[N], to[N];
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
void solve() {
	std::string s;
	std::cin >> s;
	n = s.size();
	int cnt1 = 0, cnt0 = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == '0') a[i + 1] = 0, cnt0++;
		else a[i + 1] = 1, cnt1++;
	}
	if(cnt1 != cnt0) {
		std::cout << -1;
		return;
	}
	std::vector<std::pair<int, int>> ans;
	std::stack<int> st0, st1;
	for(int i = 1; i <= n; i++) {
		if(a[i]) st1.push(i);
		else st0.push(i);
		if(st1.size() && st0.size()) {
			int x = st1.top(), y = st0.top();
			st1.pop(), st0.pop();
			to[std::min(x, y)] = std::max(x, y);
		}
	}
	int now = 1, nd = 0;
	for(int i = 1; i <= n; i++) {
		if(vis[i]) {
			now++;
			continue;
		}
		vis[i] = vis[to[i]] = true;
//		std::cout << i << ' ' << to[i] << '\n';
		if(a[i]) ans.push_back({now, 2});
		else ans.push_back({now, 1});
	}
	std::cout << ans.size() << '\n';
	for(auto x: ans) {
		std::cout << x.first << ' ' << x.second << '\n';
	}
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
