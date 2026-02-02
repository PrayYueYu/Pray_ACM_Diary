#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 1e6 + 100, M = 998244353, INF = 1e16; 
int n, m, a[N], k, b[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
void solve() {
	n = read(), k = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
	}
	sort(a + 1, a + n + 1);
	int num = 0;
	for(int i = n; i >= 1; i--) {
		if(!a[i]) break;
		b[++num] = a[i];
	}
	int lasn = n;
	n = num;
	if(n < k) {
		cout << a[lasn] << endl;
		return;
	}
	int sum = 1;
	for(int i = 1; i <= n; i++) {
		sum = (sum * b[i]) % M;
		b[i] = 0;
		if((i - 1) % (k - 1) == 0) {
			int res = n - i + 1;
			if(res < k) break;
		}
	}
	cout << sum << endl;
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
