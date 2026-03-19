#include<bits/stdc++.h>
#define int long long
const int N = 1e3 + 10, mod = 998244353, INF = 1e18;
int cnt[N * N], a[N][N], n;
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
	int flag = true;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			a[i][j] = read();
			cnt[a[i][j]]++;
			if(cnt[a[i][j]] > n * (n - 1)) flag = false;
		}
	}
	if(!flag) std::cout << "No\n";
	else std::cout << "Yes\n";
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cnt[a[i][j]]--;
		}
	}
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T = read();
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
