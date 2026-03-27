#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;

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
int getans(int n, int m) {
	int ans = 0, el = 0;
	if(n & 1) {
		n++;
		if(m & 1) {
			if(((n - 2) / 2) % 2 == 0) {
				int t = (n - 2) / 2;
				ans = std::max(ans, m * t + (m + 1) / 2);
			}
			else {
				int t = (n - 2) / 2 - 1;
				ans = std::max(ans, t * m + (m + 1));
				ans += (m - 1) / 2;
			}
		}
		else {
			ans = std::max(ans, (m / 2) * (n - 2) + (m + 1) / 2);
		}
	}
	else {
		if(m & 1) {
			if(((n - 2) / 2) % 2 == 0) {
				int t = (n - 2) / 2;
				ans = std::max(ans, m * t);
			}
			else {
				int t = (n - 2) / 2 - 1;
				ans = std::max(ans, t * m + (m + 1));
			}
		}
		else {
			ans = std::max(ans, (m / 2) * (n - 2));
		}
	}
	return ans + el;
}
void solve() {
	int n = read(), m = read();
	int ans = std::max(getans(n, m), getans(m, n));
	std::cout << ans << '\n';
}
signed main() {
	int T = read();
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
