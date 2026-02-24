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
	}
	std::sort(a + 1, a + n + 1);
	int sum = 0, cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] != a[i + 1] || i == n) {
			cnt++;
			if((double)(i - 1) >= (double)(n - 1) * 0.8) {
				sum += cnt * a[i];
			}
			cnt = 0;
		}
		else cnt++;
	}
	std::cout << sum;
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
