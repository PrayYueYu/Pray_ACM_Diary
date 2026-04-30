#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int cnt[100], a[N], n;
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
	for(int i = 0; i <= 33; i++) cnt[i] = 0;
}
void solve() {
	n = read();
	int cnt0 = 0;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		if(!a[i]) cnt0++;
		for(int j = 30; j >= 0; j--) {
			if(a[i] >> j & 1) {
				cnt[j]++;
				break;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int f = false;
		for(int j = 30; j >= 0; j--) {
			if((a[i] >> j & 1) && f) {
				ans += cnt[j];
			}
			if(a[i] >> j & 1) f = true;
		}
	}
	std::cout << ans + cnt0 * n << "\n";
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
