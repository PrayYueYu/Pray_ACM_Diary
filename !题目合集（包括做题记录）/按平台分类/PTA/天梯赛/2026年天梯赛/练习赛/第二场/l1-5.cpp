#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, m, ans[10];
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
	n = read(), m = read();
	for(int i = 1; i <= n; i++) ans[i] = 26;
	int now = 1;
	while(true) {
		if(now == m) break;
		ans[n]--;
		int t = n;
		while(true) {
			if(!ans[t]) {
				ans[t] = 26;
				ans[t - 1]--;
				t--;
			}
			else break;
		}
		now++;
		if(now == m) break;
	}
	for(int i = 1; i <= n; i++) {
		std::cout << (char)(ans[i] + 'a' - 1);
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
