#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int a, b;
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
int calcx(int l, int r) {
	return ((l + r) * (r - l + 1)) / 2;
}
int calc(int ax) {
	int sum = a * b + calcx(0, b - 1);
	int s = ax / b;
	int k = ax % b;
	int s1 = (s + 1) * sum;
	int s2 = (2 * (a + b) - (k + 1)) * k; s2 /= 2;
	int s3 = (s + 2) * (s + 1) * calcx(1, k);
	int s4 = (s + 1) * (b - k) * k * (s + 1);
	int s5 = (s + 1) * s * calcx(1, b - k);
	int ans = s1 + s2 - s3 - s4 - s5;
	return ans;
}
void solve() {
	std::cin >> a >> b;
	if(!b) {
		std::cout << 0 << '\n';
		return;
	}
	int ans = 0;
	int l = std::min(a, a - a / (b + 1) + 2);
	int r = std::max(0ll, a - a / (b + 1) - 2);
	for(int i = l; i >= r; i--) {
		ans = std::max(ans, calc(i));
	}
	std::cout << ans << '\n';
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int T = 1; 
	std::cin >> T;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
----------------------
	Writer: ÔÂö§Þ±‹¬ | 
----------------------
*/
