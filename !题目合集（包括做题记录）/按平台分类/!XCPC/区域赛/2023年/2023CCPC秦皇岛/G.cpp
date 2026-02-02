#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 2e6 + 100, M = 998244353, INF = 1e16; 
int n, m, a[N], b[N], ans;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
void solve() {
	n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		if(i > 1) ans += abs(a[i] - a[i - 1]);
	}
	for(int i = 1; i <= m; i++) {
		b[i] = read();
		if(i > 1) ans += abs(b[i] - b[i - 1]);
	}
	cout << ans << endl;
}
signed main() {
	//freopen("1.in", "r", stdin);
	int T = 1;
	while(T--) {
		solve();
	}
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*

*/
