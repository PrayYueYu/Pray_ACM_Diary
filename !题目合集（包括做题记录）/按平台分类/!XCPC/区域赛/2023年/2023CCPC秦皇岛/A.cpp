#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 1e6 + 100, M = 998244353, INF = 1e16; 
int n, ansx[N], ansy[N], k;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

void solve() {
	n = read(), k = read();
	ansx[1] = n;
	ansy[1] = 1;
	int t = 1;
	for(int i = 2; i <= 2 * n; i += 2) {
		ansx[i] = t;
		ansy[i] = t;
		if(i == 2 * n) break;
		ansx[i + 1] = t;
		ansy[i + 1] = t + 1;
		t++;
	}
	int now = 2 * n + 1;
	for(int i = 1; i <= n; i++) {
		if(now > k) break;
		for(int j = 1; j <= n; j++) {
			if(now > k) break;
			if(j == i) continue;
			if(j == i + 1) continue;
			if(i == n && j == 1) continue;
			ansx[now] = i;
			ansy[now] = j;
			now++;
		}
	}
	for(int i = 1; i <= k; i++) {
		cout << ansx[i] << " " << ansy[i] << endl;
	}
}
signed main() {
	//freopen("1.in", "r", stdin);
	int T = 1;
	while(T--) {
		solve();
	//	init();
	}
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*

*/
