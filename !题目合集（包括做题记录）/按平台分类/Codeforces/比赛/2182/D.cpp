#include<bits/stdc++.h>
#define int long long
//#define getchar getchar_unlocked
using namespace std;
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int n, a[N], b[N], cnt[N], p[N];
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
int ksm(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = (ans * x) % mod;
		x = (x * x) % mod;
		y >>= 1;
	}
	return ans;
}
int C(int x, int y) {
	if(y > x) return 0;
	int ans = 1;
	ans = ans * p[x];
	ans = (ans * ksm(p[y], mod - 2)) % mod;
	ans = (ans * ksm(p[x - y], mod - 2)) % mod;
	return ans;
}
int calc(int x, int y) {
	int ans = 1;
	int re = n - x;
	ans = C(re, y);
	ans = (ans * p[x + y]) % mod;
	ans = (ans * p[n - x - y]) % mod;

	return ans;
}
void solve() {
	n = read();
	int r = 0, ans = 0, num = 0;
	set<int> s;
	for(int i = 0; i <= n; i++) {
		a[i] = read();
		if(i) cnt[a[i]]++;
		if(i) r = max(r, a[i]);
		s.insert(a[i]);
	}
	for(auto x: s) {
		if(x != r) num += cnt[x] * (r - x - 1);
	}
	int cnt1 = cnt[r], cnt2 = min(n - cnt[r], a[0] - num);
	if(cnt2 < 0) {
		cout << 0 << '\n';
		for(int i = 0; i <= n; i++) cnt[a[i]] = 0;
		return;
	}
	ans = calc(cnt1, cnt2);
	cout << ans << '\n';
	for(int i = 0; i <= n; i++) cnt[a[i]] = 0;
}
signed main() {
	p[0] = 1;
	for(int i = 1; i <= 100; i++) {
		p[i] = (p[i - 1] * i) % mod;
	}
	int T = read();
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
------------------------------
	Writer: yueyuweihu
	Blog: prayyueyu.github.io
------------------------------
test:

*/
