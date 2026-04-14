#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 1e6 + 100, M = 998244353, INF = 1e18; 
int n, m, a[N], sum[N][3], f[N];
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
		sum[i][0] = sum[i - 1][0];
		sum[i][1] = sum[i - 1][1];
		if(a[i]) sum[i][1]++;
		else sum[i][0]++;
	}
	int ans = 0;
	for(int i = 1; i < n; i++) {
		f[i] = f[i - 1];
		if(a[i] == a[i + 1]) {
			f[i]++;
		}
	}
	for(int i = 1; i <= m; i++) {
		int l = read();
		int r = read();
		int s1 = sum[r][1] - sum[l - 1][1];
		int s2 = sum[r][0] - sum[l - 1][0];
		int s3 = f[r - 1] - f[l - 1];
		if(s1 % 3 != 0 || s2 % 3 != 0) {
			cout << "-1\n";
			continue;
		}
		ans = s1 / 3 + s2 / 3;
		if(!s3) {
			ans++;
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

*/
