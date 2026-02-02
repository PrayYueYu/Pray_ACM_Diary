#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 100, INF = 1e18;
int f[N], g[N], n, k, a[N];
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
signed main() {
	n = read(), k = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
	}
	sort(a + 1, a + n + 1);
	g[0] = -a[1];
	for(int i = 1; i < k; i++) {
		f[i] = INF;
		g[i] = f[i] - a[i + 1];
	}
	f[k] = a[k] - a[1];
	g[k] = f[k] - a[k + 1];
	int ming = g[1];
	for(int i = k + 1; i <= n; i++) {
		f[i] = min(ming + a[i], a[i] - a[1]);
		g[i] = f[i] - a[i + 1];
		ming = min(ming, g[i - k + 1]);
	}
	cout << f[n];
	return 0;
} 
