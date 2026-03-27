#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, a[N];
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
	
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		a[i + n] = a[i];
	}
	if(n == 1) {
		std::cout << 1 << '\n';
		return;
	}
	if(n == 2) {
		if(a[1] >= 0) std::cout << 1 << '\n';
		else std::cout << 2 << '\n';
		return;
	}
	int sum = 0, ans = 0, s = 2 * n;
	int f = false;
	for(int i = 1; i <= 2 * n; i++) {
		if(!f && a[i] >= 0) {
			s = i;
			f = true;
		}
//		std::cout << sum << ' ' << s << '\n';
		sum += a[i];
		if(sum < 0) {
			if(a[i] >= 0 && i <= n) sum = a[i], s = i;
			else sum = 0, s = 2 * n, f = false;
//			f =false;
		}
		else {
			if(i - s + 1 == n) {
				ans = s;
				break;
			}
		}
	}
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
