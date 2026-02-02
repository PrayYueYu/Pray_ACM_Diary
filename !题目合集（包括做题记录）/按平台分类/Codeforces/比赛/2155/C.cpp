#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 1e6 + 100, M = 998244353, INF = 1e18; 
int n, k, a[N], b[N], f[N], g[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) {
		b[i] = 0;
		g[i] = f[i] = 0;
	}
	int ans = 0, F = 1, fx = 0;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		if(a[i] > n) {
			F = false;
		}
		int d = abs(a[i] - a[i - 1]);
		int dx = a[i] - a[i - 1];
		if(i >= 2) {//cout << F << endl;
			if(d == 0) {
				if(b[i - 1] == -1) {
					b[i] = 1;
				}
				else if(b[i - 1] == 1) {
					b[i] = -1;
				}
				else {
					b[i - 1] = -1;
					b[i] = 1;
					fx = 1;
				}
			}
			else if(dx == 1) {
				b[i] = -1;//-1×ó
				if(!b[i - 1]) b[i - 1] = -1;
				else if(b[i - 1] != -1) {
					F = false;
				} 
			}
			else if(dx == -1) {
				b[i] = 1;
				if(!b[i - 1]) b[i - 1] = 1;
				else if(b[i - 1] != 1) {
					F = false;
				}
			}
			else if(d >= 2) {
				F = false;
			}
			
		}
	}	
	if(n == 1) {
		cout << 2 << endl;
		return;
	}
	for(int i = 1; i <= n; i++) {
		f[i] = f[i - 1];
		if(b[i] == -1) f[i]++;
	}
	g[n + 1] = 0;
	for(int i = n; i >= 1; i--) {
		g[i] = g[i + 1];
		if(b[i] == 1) g[i]++;
	}
	for(int i = 1; i <= n; i++) {
		int s = f[i - 1] + g[i + 1] + 1;
		if(s != a[i]) F = false;
	}
//	cout << b[1] << " " << b[2] << " " << b[3] << " " << b[4] << endl;
	if(F) ans++;
	if(!fx) {
		cout << ans << endl;
		return;
	}
	
	
	for(int i = 1; i <= n; i++) {
		b[i] = 0;
		g[i] = f[i] = 0;
	}
	F = 1, fx = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] > n) {
			F = false;
		}
		int d = abs(a[i] - a[i - 1]);
		int dx = a[i] - a[i - 1];
		if(i >= 2) {//cout << F << endl;
			if(d == 0) {
				if(b[i - 1] == -1) {
					b[i] = 1;
				}
				else if(b[i - 1] == 1) {
					b[i] = -1;
				}
				else {
					b[i - 1] = 1;
					b[i] = -1;
				}
			}
			else if(dx == 1) {
				b[i] = -1;//-1×ó
				if(!b[i - 1]) b[i - 1] = -1;
				else if(b[i - 1] != -1) {
					F = false;
				} 
			}
			else if(dx == -1) {
				b[i] = 1;
				if(!b[i - 1]) b[i - 1] = 1;
				else if(b[i - 1] != 1) {
					F = false;
				}
			}
			else if(d >= 2) {
				F = false;
			}
			
		}
	}	
	if(n == 1) {
		cout << 2 << endl;
		return;
	}
	for(int i = 1; i <= n; i++) {
		f[i] = f[i - 1];
		if(b[i] == -1) f[i]++;
	}
	g[n + 1] = 0;
	for(int i = n; i >= 1; i--) {
		g[i] = g[i + 1];
		if(b[i] == 1) g[i]++;
	}
	for(int i = 1; i <= n; i++) {
		int s = f[i - 1] + g[i + 1] + 1;
		if(s != a[i]) F = false;
		if(!b[i]) fx = 1;
	}
	if(F) ans++;
	cout << ans << endl;
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

*/
