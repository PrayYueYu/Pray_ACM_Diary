#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 2e6 + 100, M = 998244353, INF = 1e18; 
int n, q, sum[N], a[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
int calc(int x, int y) {
	x += y;
	if(x > n) return x - n;
	return x;
}
signed main() {
	//freopen("1.in", "r", stdin);
	n = read(); q = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		sum[i] = sum[i - 1] + a[i];
	}
	int now = 0;
	for(int i = 1; i <= q; i++) {
		int op = read();
		if(op == 1) {
			int c = read();
			now += c;
			if(now > n) now -= n;
		}
		else {
			int l = read(), r = read();
			l = calc(l, now);
			r = calc(r, now);
			if(l <= r) {
				cout << sum[r] - sum[l - 1] << endl;
				continue;
			}
			cout << sum[n] - sum[l - 1] + sum[r] << endl;
		}
	}
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*

*/
