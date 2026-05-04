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
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		sum += a[i];
	} 
	if(sum % n != 0) {
		std::cout << "-1\n";
		return;
	}
	int ave = sum / n;
	std::vector<int> v[3];
	for(int i = n; i >= 2; i--) {
		if(a[i] < ave) {
			std::cout << "-1\n";
			return;
		}
		v[i & 1].push_back(a[i] - ave);
		a[i - 1] += a[i] - ave;
	}
	if(a[1] != ave) {
		std::cout << "-1\n";
		return;
	}
	int ans = 0, now = 0;
	for(auto x: v[0]) {
		if(now < x) ans += x - now;
		now = x;
	}
	now = 0;
	for(auto x: v[1]) {
		if(now < x) ans += x - now;
		now = x;
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
