#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 100, M = 998244353, INF = 1e16 + 10;
int n, a[N], f[N];
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
int getx(int x, int y) {
	if(y == 2) {
		return abs(a[x] - a[x - 1]);
	}
	return max(a[x], max(a[x - 1], a[x - 2])) - min(a[x], min(a[x - 1], a[x - 2]));
}
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	a[n + 1] = a[1]; a[n + 2] = a[2]; a[n + 3] = a[3];
	int ans = INF;
	for(int i = 1; i <= 3; i++) {
		for(int j = 1; j <= n + 4; j++) f[j] = INF;
		f[i] = INF;
		f[i - 1] = 0;
		for(int j = i + 1; j <= i + n - 1; j++) {
			if(j - 2 >= i - 1)
				f[j] = min(f[j], f[j - 2] + getx(j, 2));
			if(j - 3 >= i - 1)
				f[j] = min(f[j], f[j - 3] + getx(j, 3));
		}
		ans = min(ans, f[i + n - 1]);
	}
	cout << ans << endl;
}
signed main() {
	int T = read();
	while(T--) {
		solve();
	}
	return 0;
}
