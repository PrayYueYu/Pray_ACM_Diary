#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 1e6 + 100, M = 998244353, INF = 1e18; 
int n, m, sum[N][4], a[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
int check(int x) {
	int t = log2(x);
	if((1ll << t) + 1 == x) return 1;
	if((1ll << t) == x) return 3;
	return 2;
}
void solve() {
	n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		int x = a[i];
		int s1 = 0, s2 = 0, s3 = 0;
		while(true) {
			if(x == 1) break;
			s1++;
			x /= 2;
		}
		if(check(a[i]) == 1) s2++;
		else if(check(a[i]) == 2) s3++;
		sum[i][0] = sum[i - 1][0] + s1;
		sum[i][1] = sum[i - 1][1] + s2;
		sum[i][2] = sum[i - 1][2] + s3;
	}
	for(int i = 1; i <= m; i++) {
		int l = read(), r = read();
		int s1 = sum[r][0] - sum[l - 1][0];
		int s2 = sum[r][1] - sum[l - 1][1];
		int s3 = sum[r][2] - sum[l - 1][2];
		s2 /= 2;
		cout << s1 + s2 + s3 << endl;
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
