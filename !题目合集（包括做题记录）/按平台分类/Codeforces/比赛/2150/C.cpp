#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define int long long
using namespace std;
const int N = 4e5 + 100, M = 1e9 + 7, INF = 1e9; 
int n, m, a[N], sum1[N], sum2[N];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
void init() {
	for(int i = 0; i <= 2 * n + 10; i++) {
		sum1[i] = sum2[i] = 0;
	}
}
void solve() {
	n = read();
	for(int i = 1; i <= 2 * n; i++) a[i] = read();
	sort(a + 1, a + 2 * n + 1);
	int f = -1;
	for(int i = 1; i <= 2 * n; i++) {
		sum1[i] = sum1[i - 1] + f * a[i];
		sum2[i] = sum2[i - 1] - f * a[i];
		f = -f;
	}
	int ans = sum1[2 * n], sum = 0;
	for(int i = 1; i <= n; i++) {
		int r = 2 * n - i + 1, l = i;
		if(i & 1) {
			ans = sum1[r] - sum1[l - 1];
		}
		else ans = sum2[r] - sum2[l - 1];
		cout << sum + ans << " ";
		sum += a[r] - a[l];
	}
	cout << endl;
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
