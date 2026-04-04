#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, a[N], b[N], m;
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
	a[0] = -1;
	int sum = 0, now = n + 1, f = false;
	if(mid > a[n]) {
		sum += mid * b[now];
		now--;
		f = true;
	}
	if(sum >= m) return true;
	for(int i = n; i >= 1; i--) {
		if(a[i] >= mid && mid >= a[i - 1] && !f) {
			f = true;
			sum += mid * b[now];
			now--;
		}
		sum += a[i] * b[now];
		now--;
		if(sum >= m) return true;
	}
	if(sum >= m) return true;
	return false;
}
void solve() {
	n = read(), m = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	std::sort(a + 1, a + n + 1);
	for(int i = 1; i <= n + 1; i++) b[i] = read();
	std::sort(b + 1, b + n + 2);
	int l = 0, r = 2000000000;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	std::cout << l << '\n';
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
1
2 1
1 2
1 2 3
*/
