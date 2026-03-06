#include<bits/stdc++.h>
#define int long long
const int N = 1e5 + 10, mod = 998244353, INF = 1e18;
int a[N], b[N], cnt, ALL, n, k;
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
bool check() {
	for(int i = 1; i <= n; i++) {
		b[i] = a[i];
	}
	std::sort(b + 1, b + n + 1);
	int f = 1;
	for(int i = 1; i <= n; i++) {
		if(f < b[i]) return false;
		if(f == b[i]) f++;
	}
	return true;
}
void dfs(int t) {
	if(t == k + 1) {
		if(check()) {
			cnt++;
			cnt %= mod;
		}
		return;
	}
	for(int i = 1; i <= n; i++) {
		a[i]--;
		if(!a[i]) {
			a[i]++;
			continue;
		}
		dfs(t + 1);
		a[i]++;
	}
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
void solve() {
	n = read(), k = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	dfs(1);
	ALL = ksm(n, k);
	int inv = ksm(ALL, mod - 2);
	std::cout << (cnt * inv) % mod;
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
