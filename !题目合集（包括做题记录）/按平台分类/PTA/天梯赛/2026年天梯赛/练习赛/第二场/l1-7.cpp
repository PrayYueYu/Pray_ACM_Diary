#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int a[N], n, ans[200][20][20], to[N];
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
	n = read();
	int maxn = -1;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		maxn = std::max(maxn, a[i]);
	}
	int now = 1;
	for(int i = 1; i <= maxn; i++) {
		int cnt = 0;
		for(int j = 1; j <= n; j++) {
			if(a[j] >= i) cnt++;
		}
		if(cnt == 1) {
			for(int j = 1; j <= n; j++) {
				if(a[j] == maxn) {
					if(to[now - 1] == j) now++;
					for(int k = 1; k <= 10; k++) {
						ans[j][i][k] = now;
						to[now] = j;
						now += 2;
					}
				}
			}
			
			continue;
		}
		int st = now;
		for(int j = 1; j <= n; j++) {
			if(a[j] < i) continue;
			now = st;
			st++;
			for(int k = 1; k <= 10; k++) {
				ans[j][i][k] = now;
				to[now] = j;
				now += cnt;
			}
		}
		now -= cnt;
		now++;
	}
	for(int i = 1; i <= n; i++) {
		std::cout << "#" << i << '\n';
		for(int j = 1; j <= a[i]; j++) {
			for(int k = 1; k <= 10; k++) {
				std::cout << ans[i][j][k];
				if(k != 10) std::cout << ' ';
			}
			std::cout << '\n';
		}
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
