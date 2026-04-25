#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int a[N], cnt[N], n, m;
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
	for(int i = 1; i <= n; i++) {
		cnt[a[i]] = 0;
	}
}
void solve() {
	n = read(), m = read();
	int minn = INF, sum = 0, now = 0, L = 1;
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= n; i++) {
		if(a[i] > m) {
			sum++;
			continue;
		}
		if(!cnt[a[i]]) now++;
		cnt[a[i]]++;
		sum++;
	
		if(now == m) {
			while(true) {
				if(L == i) break;
				if(a[L] > m || cnt[a[L]] >= 2) {
					cnt[a[L]]--;
					sum--;
					L++;
				}
				else break;
			}
			minn = std::min(minn, sum - m);
		}
	}
	if(minn == INF) std::cout << -1 << '\n';
	else std::cout << minn << '\n';
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
