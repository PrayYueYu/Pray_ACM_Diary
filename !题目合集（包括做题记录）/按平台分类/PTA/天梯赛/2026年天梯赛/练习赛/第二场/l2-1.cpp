#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, q, k, las[N], vis[N];
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
	n = read(), q = read(), k = read();
	std::priority_queue<std::pair<int, int>> qu;
	int now = 0;
	for(int i = 1; i <= q; i++) {
		int x = read();
		las[x] = i;
		qu.push({-i, x});
		if(vis[x]) {
			std::cout << "-1\n";
			continue;
		}
		if(now < k) {
			now++;
			vis[x] = true;
			std::cout << "-1\n";
			continue;
		}
		int ans = 0;
		while(!qu.empty()) {
			int u = qu.top().second;
			int t = -qu.top().first;
			qu.pop();
			if(las[u] != t) continue;
			ans = u;
			vis[u] = false;
			vis[x] = true;
			break;
		}
		std::cout << ans << '\n';
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
