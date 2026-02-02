#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 4e5 + 100, M = 1e9 + 7, INF = 1e16; 
int n, a[3][N], to[N], Max[3][N], Min[3][N];
ll read() {
	int x;
	scanf("%lld", &x);
	return x;
}

void solve() {
	n = read();
	for(int i = 1; i <= 2; i++) {
		for(int j = 1; j <= n; j++) {
			a[i][j] = read();
		}
	}
	for(int i = 1; i <= n; i++) {
		Min[1][i] = a[1][i];
		Max[1][i] = a[1][i];
		if(i > 1) {
			Min[1][i] = min(Min[1][i], Min[1][i - 1]);
			Max[1][i] = max(Max[1][i], Max[1][i - 1]);
		}
	}
	for(int i = n; i >= 1; i--) {
		Min[2][i] = a[2][i];
		Max[2][i] = a[2][i];
		if(i < n) {
			Min[2][i] = min(Min[2][i], Min[2][i + 1]);
			Max[2][i] = max(Max[2][i], Max[2][i + 1]);
		}
	}
	for(int i = 1; i <= 2 * n; i++) to[i] = 2 * n + 1;
	for(int i = 1; i <= n; i++) {
		int l = min(Min[1][i], Min[2][i]);
		int r = max(Max[1][i], Max[2][i]);
		to[l] = min(to[l], r);
	}
	for(int i = 2 * n - 1; i >= 1; i--) {
		to[i] = min(to[i], to[i + 1]);
	}
	int ans = 0;
	for(int i = 1; i <= 2 * n; i++) {
		ans += (2 * n - to[i] + 1);
	}
	cout << ans << '\n';
}
signed main(){
	int T = read();
	while(T--) solve();
	return 0;
}
//ÔÂö§¡¤Þ±‹¬ 
/*

*/
