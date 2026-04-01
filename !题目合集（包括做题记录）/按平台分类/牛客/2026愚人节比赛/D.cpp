#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, vis[N], a[N];
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
bool check() {
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(vis[i]) cnt++;
	}
	for(int i = 1; i <= n; i++) {
		if(vis[i] && cnt >= a[i]) return false;
		if(!vis[i] && cnt < a[i]) return false;
	}
	return true;
}
void dfs(int t) {
	if(t == n + 1) {
		if(check()) {
			int cnt = 0;
			for(int i = 1; i <= n; i++) {
				if(vis[i]) cnt++;
			}
			std::cout << cnt << ' ';
			for(int i = 1; i <= n; i++) {
				if(vis[i]) std::cout << i << ' ';
			}
			exit(0);
		}
		return;
	}
	vis[t] = true;
	dfs(t + 1);
	vis[t] = false;
	dfs(t + 1);
}
void solve() {
	n = read() + 1;
	for(int i = 1; i < n; i++) {
		a[i] = read();
	}
	a[n] = 3;
	dfs(1);
	std::cout << -1;
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
