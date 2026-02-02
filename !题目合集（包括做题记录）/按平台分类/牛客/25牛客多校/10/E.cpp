#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 2e6 + 100, M = 998244353, INF = 1e18; 
int n, m, a[N], f[N][3];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

void solve() {
	n = read(), m = read();
	int Max = 0;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		Max = max(Max, a[i]);
	}
	int ans = INF;
	if(m == 1) {
		f[1][0] = Max - a[1];
		for(int i = 2; i <= n; i++) {
			if(a[i] >= a[i - 1]) f[i][0] = f[i - 1][0];
			else f[i][0] = f[i - 1][0] + a[i - 1] - a[i];
		}
		cout << f[n][0] << endl;
		return;
	}
	else {
		for(int h0 = 0; h0 <= 2 * Max; h0++) {
			for(int h1 = 0; h1 <= 2 * Max; h1++) {
				for(int i = 1; i <= n; i++) {
					f[i][0] = f[i][1] = INF;
				}
				if(a[1] > h0) f[1][0] = INF;
				else f[1][0] = h0 - a[1];
				if(a[1] > h1) f[1][1] = INF;
				else f[1][1] = h1 - a[1];
				for(int i = 2; i <= n; i++) {
					if(a[i] > h0) f[i][0] = INF;
					else {
						if(a[i] >= a[i - 1]) {
							f[i][0] = min(f[i][0], f[i - 1][0]);
						}
						else {
							f[i][0] = min(f[i][0], f[i - 1][0] + a[i - 1] - a[i]);
						}
						if(h0 - a[i] <= h1 - a[i - 1]) {
							f[i][0] = min(f[i][0], f[i - 1][1]);
						}
						else {
							f[i][0] = min(f[i][0], f[i - 1][1] + (h0 - a[i]) - (h1 - a[i - 1]));
						}
					}
					if(a[i] > h1) f[i][1] = INF;
					else {
						if(a[i] >= a[i - 1]) {
							f[i][1] = min(f[i][1], f[i - 1][1]);
						}
						else {
							f[i][1] = min(f[i][1], f[i - 1][1] + a[i - 1] - a[i]);
						
						}	
						if(h1 - a[i] <= h0 - a[i - 1]) {
							f[i][1] = min(f[i][1], f[i - 1][0]);
						}
						else {
							f[i][1] = min(f[i][1], f[i - 1][0] + (h1 - a[i]) - (h0 - a[i - 1]));
						}
					} 
				}
				ans = min(ans, f[n][0]);
				ans = min(ans, f[n][1]);
			}
		}
	}
	cout << ans << endl;
}
signed main() {
	//freopen("1.in", "r", stdin);
	int T = read(); 
	while(T--) {
		solve();
		//init();
	}
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*

*/
