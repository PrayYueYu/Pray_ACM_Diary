#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 2e5 + 100, M = 1e9 + 7, INF = 1e9; 
int n, m, a[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
void solve() {
	n = read();
	m = read();
	for(int  i = 1; i <= m; i++) a[i] = read();
	int f = true;
	int Max1 = 0, Max2 = 0;
//	a[0] = a[1] - 1;
	for(int i = 1; i <= m; i++) {
		if(a[i] != a[i + 1] - 1 && i != m) {
			f = false;
		}
	}
	if(!f) cout << 1 << endl;
	else {
		int Max = a[m];
		cout << n - Max + 1 << endl;
	}
}
signed main() {
	//freopen("1.in", "r", stdin);
	int T = read();
	while(T--) {
		solve();
	//	init();
	}
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*

*/
