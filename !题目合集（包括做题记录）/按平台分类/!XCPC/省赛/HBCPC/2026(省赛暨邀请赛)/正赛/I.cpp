#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, m, a[N];
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
bool check(int mid) {
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		sum += mid / a[i];
		if(sum >= m) return true;
	}
	return false;
}
void solve() {
	n = read(), m = read();
	int maxn = -1;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		maxn = std::max(maxn, a[i]);
	}
	int l = 0, r = maxn * (m + 1);
	while(l < r) {
		int mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	std::cout << l;
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
