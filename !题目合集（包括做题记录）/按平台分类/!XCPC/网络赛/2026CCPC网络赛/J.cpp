#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10;
int f[N], a[N], sum[N], n, m, k;
bool check(int x) {
	int e = 0, now = 0;
	for(int i = 1; i <= 3 * n; i++) {
		now -= a[i - 1];
		while(true) {
			if(e == 3 * n || now + a[e + 1] > x) break;
			now += a[++e];
		}
		f[i] = e;
	}
	int len = n / k + 1;
	int s = 0, t = 0, maxn = -1;
	len = std::min(len, n);
	for(int i = 1; i <= 2 * n; i++) {
		if(i + len - 1 > 2 * n) break;
		if(maxn < sum[i + len - 1] - sum[i - 1]) {
			s = i;
			t = i + len - 1;
		}
	}
	for(int i = s; i <= t; i++) {
		now = i;
		for(int j = 1; j <= k; j++) {
			now = f[now] + 1;
			if(now > i + n - 1) break;
		}
		if(now > i + n - 1) return true;
	}
	return false;
}
void solve() {
	std::cin >> n >> m >> k;
	int maxn = -1;
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
		a[i + n] = a[i];
		a[i + 2 * n] = a[i];
		maxn = std::max(maxn, a[i]);
	}
	for(int i = 1; i <= 2 * n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	int l = maxn, r = sum[n];
	while(l < r) {
		int mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	std::cout << l << '\n';
	std::cout << l * (m - 1) + sum[n];
}
signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}
/*
----------------------
	Writer: ÔÂö§Þ±‹¬ | 
----------------------
4 3 2
3 2 1 4
*/
