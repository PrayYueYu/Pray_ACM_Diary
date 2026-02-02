#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 4e5 + 100, M = 998244353, INF = 1e9; 
int n, m, a[N], fac[N], invfac[N], num[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
void init() {
	for(int i = 0; i <= n + 10; i++) num[i] = 0;
}
int ksm(int x, int y) {
	int ans = 1;
	while(y) {
		if(y & 1) ans = (ans * x) % M;
		x = (x * x) % M;
		y >>= 1;
	}
	return ans;
}
int C(int x, int y) {
	if(x < y) return 0;
	int ans = fac[x];
	ans = (ans * invfac[y]) % M;
	ans = (ans * invfac[x - y]) % M;
	return ans;
}
void solve() {
	n = read();
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		sum += a[i];
	}
	int l = 1, r = n;
	for(int i = 1; i <= n; i++) {
		if(l < r) num[i] = 2;
		else if(l == r) num[i] = 1;
		else num[i] = 0;
		l++, r--;
	}
	if(sum != n) {
		cout << 0 << endl;
		return;
	}
	int ans = 1ll, res = 0;
	for(int i = n; i >= 1; i--) {
		if(num[i] + res < a[i]) {
			ans = 0;
			break;
		}
		int now = num[i] + res;
		if(!now) continue;
		if(now == a[i]) {
			res = 0;
			continue;
		}
		else {
			ans = (ans * C(now, a[i])) % M;
			res = now - a[i];
		}
	}
	cout << ans << endl;
}
signed main() {
	//freopen("1.in", "r", stdin);
	fac[0] = 1;
	for(int i = 1; i <= N - 10; i++) {
		fac[i] = fac[i - 1] * i;
		fac[i] %= M;
	}
	invfac[N - 10] = ksm(fac[N - 10], M - 2);
	for (int i = N - 11; i >= 0; i--) {
	    invfac[i] = invfac[i + 1] * (i + 1) % M;
	}
	int T = read();
	while(T--) {
		solve();
		init();
	}
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*

*/
