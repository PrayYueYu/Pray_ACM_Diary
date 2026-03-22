#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int x[N], y[N], ans, n;
int read() {
	int x;
	std::cin >> x;
	return x;
}
bool check(int i, int j, int k) {
	int x1 = (x[i] - x[j]), y1 = y[i] - y[j];
	int x2 = x[i] - x[k], y2 = y[i] - y[k];
	if(x1 * x2 + y1 * y2 == 0) return true;
	return false;
}
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) {
		x[i] = read(); y[i] = read();
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			for(int k = j + 1; k <= n; k++) {
				if(check(i, j, k) || check(j, i, k) || check(k, i, j)) {
					ans++;
//					std::cout << i <<' ' << j << ' ' << k <<'\n';
				}
			}
		}
	}
	std::cout << ans;
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T = 1;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*

*/
