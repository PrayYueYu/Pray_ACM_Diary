#include<bits/stdc++.h>
//#define getchar getchar_unlocked
#define int long long
using namespace std;
const int N = 1e6 + 10, mod = 998244353, INF = 1e18;
int n, tr[N], a[N], b[N], cnt, f[3][N];
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x * f;
}
int lowbit(int x) {
	return x & (-x);
}
void add(int x, int y) {
	while(x <= cnt) {
		tr[x] += y;
		tr[x] %= mod;
		x += lowbit(x);
	}
}
int query(int x) {
	int ans = 0;
	while(x) {
		ans += tr[x];
		ans %= mod;
		x -= lowbit(x);
	}
	return ans;
}
map<int, int> mp;
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) {
		a[i] = b[i] = read();
	}
	sort(b + 1, b + n + 1);
	for(int i = 1; i <= n; i++) {
		if(!mp[b[i]]) mp[b[i]] = ++cnt;
	}
	for(int i = 1; i <= n; i++) a[i] = mp[a[i]];
	for(int i = 1; i <= n; i++) {
		f[1][i] = query(a[i] - 1) + 1;
		add(a[i], f[1][i]);
	}
	for(int i = 0; i <= cnt; i++) tr[i] = 0;
	for(int i = n; i >= 1; i--) {
		f[2][i] = query(a[i] - 1) + 1;
		add(a[i], f[2][i]);
	}
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		int now = ((f[1][i] + mod) % mod * ((f[2][i] + mod) % mod)) % mod;
		sum = (sum + now) % mod;
	}
	cout << sum;
}
signed main() {
	int T = 1;
	while(T--) solve();
	return 0;
}
/*
	Writer: yueyu_weihu
	Blog: prayyueyu.github.io
*/
