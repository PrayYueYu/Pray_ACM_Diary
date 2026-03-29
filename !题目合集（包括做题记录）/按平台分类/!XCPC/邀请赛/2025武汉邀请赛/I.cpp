#include<bits/stdc++.h>
#define int long long
const int N = 1e4 + 10, mod = 998244353, INF = 1e18;
int n, k, a[100][100], vis[N];
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
void init() {
	for(int i = 0; i <= n * n + 5; i++) {
		vis[i] = 0;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			a[i][j] = 0;
		}
	}
}
void solve() {
	n = read(), k = read();
	if(k < n || k > n * n - n + 1) {
		std::cout << "No\n";
		return;
	}
	std::cout << "Yes\n";
	k--;
	for(int i = 1; i <= n; i++) {
		a[i][i] = ++k;
		vis[k] = true;
	}
	int now = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(a[i][j]) continue;
			now++;
			if(vis[now]) {
				while(true) {
					if(!vis[now]) break;
					now++;
				}
			}
			a[i][j] = now;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			std::cout << a[i][j] << ' ';
		}
		std::cout << '\n';
	}
}
signed main() {
	int T = read();
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*

*/
