#include<bits/stdc++.h>
//#define getchar getchar_unlocked
using namespace std;
const int N = 1e6 + 10, M = 1e9 + 7;
int n, m, a[N], b[N], sum[N], num[N];
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x * f;
}
void solve() {
	n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read(), b[i] = read();
		num[a[i]]++;
		sum[a[i]] += b[i];
	}
	for(int i = 1; i <= m; i++) {
		double ans = (double)sum[i] / num[i];
		printf("%.8lf\n", ans);
	}
}
signed main() {
	int T = 1; 
	while(T--) solve();
	return 0;
}

/*

*/
