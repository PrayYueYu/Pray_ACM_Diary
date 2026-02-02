#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 1e6 + 100, M = 998244353, INF = 1e16; 
int n, a[N], vis[N], k;
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
void init() {
	for(int i = 0; i <= n + 5; i++) vis[i] = false;
}
void solve() {
	n = read();k = read();
	int ans1 = 0, ans2 = 0;
	for(int i = 1; i <= n; i++) a[i] = read();
	
	for(int i = 1; i <= n; i++) {
		if(a[i] == k) ans1++;
		vis[a[i]] = true;
	}
	for(int i = 0; i < k; i++) {
		if(!vis[i]) ans2++;
	}
	//cout << ans1 << endl;
	cout << max(ans1, ans2) << endl;
}
signed main() {
	//freopen("1.in", "r", stdin);
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
