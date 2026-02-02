#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 100;
int ans[N];
int g[N];
int n, q, a[N];
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
void init() {
	for(int i = 0; i <= 4 * n + 100; i++) {
		g[i] = 0;
	}
}
void add(int p, int l, int r, int u, int op) {
	if(u < l || u > r) return;
	if(l == r) {
		if(op == 1) g[p] = u;
		else g[p] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	add(p * 2, l, mid, u, op);
	add(p * 2 + 1, mid + 1, r, u, op);
	g[p] = __gcd(g[p * 2], g[p * 2 + 1]);
}
void calc() {
	int gx = g[1];
	if(!gx) {
		cout << n << '\n';
		return;
	}
	if(ans[gx]) {
		cout << ans[gx] << '\n';
		return;
	}
	int sum = 0;
	for(int j = 1; j <= sqrt(gx); j++) {
		if(gx % j != 0) continue;
		int s1 = j, s2 = gx / j;
		sum++;
		if(s1 != s2) sum++;
	}
	cout << sum << '\n';
	ans[gx] = sum;	
}
void solve() {
	n = read(), q = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
	}
	for(int i = 1; i < n; i++) {
		if(a[i] > a[i + 1]) {
			add(1, 1, n, i, 1);
		}
	}
	calc();
	for(int i = 1; i <= q; i++) {
		int p = read(), v = read();
		if(a[p - 1] > a[p] && a[p - 1] <= v && p >= 2) {
			add(1, 1, n, p - 1, 0);
		}
		if(a[p - 1] <= a[p] && a[p - 1] > v && p >= 2) {
			add(1, 1, n, p - 1, 1);
		}
		
		if(a[p] > a[p + 1] && v <= a[p + 1] && p < n) {
			add(1, 1, n, p, 0);
		}
		if(a[p] <= a[p + 1] && v > a[p + 1] && p < n) {
			add(1, 1, n, p, 1);
		}
		a[p] = v;
		calc();
	}
}
signed main() {
	int T = read();
	while(T--) {
		solve();
		init();
	}
	return 0;
}
