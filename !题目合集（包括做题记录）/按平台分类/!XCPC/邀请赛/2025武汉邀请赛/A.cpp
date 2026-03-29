#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;
int n, a[N], l[N], r[N], q;
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
void init() {
	for(int i = 0; i <= n; i++) {
		l[i] = r[i] = a[i] = 0;
	}
}
bool merge(int i, int L, int R) {
	if(!l[i] && !r[i]) {
		l[i] = L;
		r[i] = R;
		return true;
	}
	if(r[i] < L || R < l[i]) return false;
	l[i] = std::max(l[i], L);
	r[i] = std::min(r[i], R);
	return true;
}
void solve() {
	n = read(), q = read();
	int f = true;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
	}
	for(int i = 1; i <= q; i++) {
		int p = read(), L = read(), R = read();
		if(!merge(p, L, R)) f = false; 
	}
	if(!f) {
		std::cout << -1 << '\n';
		return;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(!l[i]) continue;
		if(a[i] <= r[i] && a[i] >= l[i]) continue;
		if(a[i] < l[i]) ans += l[i] - a[i];
		else ans += a[i] - r[i];
	}
	std::cout << ans << '\n';
}
signed main() {
	int T = read();
	while(T--) {
		solve();
		init();
	}
	return 0;
}
/*

*/
