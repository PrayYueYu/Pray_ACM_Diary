#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 1e6 + 100, M = 998244353, INF = 1e18; 
int n, m, q, a[N], b[N], suma[N], sumb[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
int calc(int x, int z) {
	int y = z - x;
	return suma[x] + sumb[y];
}
void solve() {
	n = read(), m = read(), q = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= m; i++) b[i] = read();
	sort(a + 1, a + n + 1, greater<int>());
	sort(b + 1, b + m + 1, greater<int>());
	for(int i = 1; i <= n; i++) {
		suma[i] = suma[i - 1] + a[i];
	}
	for(int i = 1; i <= m; i++) {
		sumb[i] = sumb[i - 1] + b[i];
	}
	for(int i = 1; i <= q; i++) {
		int x = read(), y = read(), z = read();
		int l = z - min(z, y), r = min(z, x);
		while(r - l > 2) {
			int lmid = l + (r - l) / 3;
			int rmid = r - (r - l) / 3;
			if(calc(lmid, z) > calc(rmid, z)) r = rmid;
			else l = lmid;
		}
		int ans = -INF;
		for(int i = l; i <= r; i++) {
			ans = max(ans, calc(i, z));
		}
		cout << ans << endl;
	}
}
signed main() {
	//freopen("1.in", "r", stdin);
	int T = read();
	while(T--) {
		solve();
	}
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*
1 1000000000yy
6
1 2 3 4 5 6
*/
