#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 100;
int sumH[20], sumL[20], a[20][20], n, l, ans;
void dfs(int x, int y) {
	if(x == n + 1) {
		if(sumL[n] == l) ans++;
		return;
	}
	if(y == n) {
		a[x][y] = l - sumH[x];
		if(a[x][y] < 0) return;
		sumH[x] += a[x][y];
		sumL[y] += a[x][y];
		dfs(x + 1, 1);
		sumL[y] -= a[x][y];
		sumH[x] -= a[x][y];
		return;
	}
	if(x == n) {
		a[x][y] = l - sumL[y];
		if(a[x][y] < 0) return;
		sumH[x] += a[x][y];
		sumL[y] += a[x][y];
		dfs(x, y + 1);
		sumL[y] -= a[x][y];
		sumH[x] -= a[x][y];
		return;
	}
	for(int i = 0; i <= l; i++) {
		if(sumH[x] + i > l || sumL[y] + i > l) break;
		a[x][y] = i;
		sumH[x] += a[x][y];
		sumL[y] += a[x][y];
		dfs(x, y + 1);
		sumL[y] -= a[x][y];
		sumH[x] -= a[x][y];
	}
}
void solve() {
	std::cin >> l >> n;
	dfs(1, 1);
	std::cout << ans;
}
signed main() {
	int T = 1;
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
