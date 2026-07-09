#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, d;
int a[N], sum[N];
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
	std::cin >> n >> d;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
		a[i + n] = a[i];
	}
	for(int i = 1; i <= 2 * n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	int ans = 0;
	for(int i = d + 1; i <= d + n; i++) {
		int r = i + d, l = i - d;
		int now = sum[r] - sum[l - 1] - a[i];
		if(a[i] * 2 * d - now > 0) ans += a[i] * 2 * d - now;
	}
	std::cout << ans << '\n';
}
signed main() {
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
	Writer: ����ޱ�� 
*/
